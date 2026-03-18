#include "../Headers/SFUIL/System/Layout/LayoutDataStore.hpp"
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <stdexcept>
#include <format>

namespace sfui
{
	LayoutDataStore::ComponentDataStore::ComponentDataStore(int _size) : size(_size), componentsCountPerChunk(32768 / _size), chunkCount(0), m_chunks(nullptr)
	{
	}

	void LayoutDataStore::ComponentDataStore::Dispose()
	{
		if (m_chunks != nullptr)
		{
			for (int i = 0; i < chunkCount; ++i)
			{
				if (m_chunks[i].buffer != nullptr)
				{
					_aligned_free(m_chunks[i].buffer);
					m_chunks[i].buffer = nullptr;
				}
			}

			_aligned_free(m_chunks);
			chunkCount = 0;
			m_chunks = nullptr;
		}
	}

	uint8_t* LayoutDataStore::ComponentDataStore::GetComponentDataPtr(int _index)
	{
		int num = _index / componentsCountPerChunk;
		int num2 = _index % componentsCountPerChunk;
		return m_chunks[num].buffer + num2 * size;
	}

	void LayoutDataStore::ComponentDataStore::ResizeCapacity(int capacity)
	{
		int num = capacity / componentsCountPerChunk + 1;
		if (num > chunkCount)
		{
			m_chunks = static_cast<Chunk*>(ResizeArray(m_chunks, chunkCount, num, sizeof(Chunk), alignof(Chunk)));
			for (int i = 0; i < num; ++i)
			{
				m_chunks[i] = Chunk
				{
					reinterpret_cast<uint8_t*>(_aligned_malloc(32768ull, 4))
				};
			}
		}
		else if (num < chunkCount)
		{
			for (int num2 = chunkCount - 1; num2 >= num; --num2)
			{
				_aligned_free(m_chunks[num2].buffer);
			}

			m_chunks = reinterpret_cast<Chunk*>(ResizeArray(m_chunks, chunkCount, num, sizeof(Chunk), alignof(Chunk)));
		}

		chunkCount = num;
	}

	void LayoutDataStore::SetNextFreeIndex(ComponentDataStore* _ptr, int _index, int _value)
	{
		*reinterpret_cast<int*>(_ptr->GetComponentDataPtr(_index)) = _value;
	}

	int LayoutDataStore::GetNextFreeIndex(ComponentDataStore* _ptr, int _index)
	{
		return *reinterpret_cast<int*>(_ptr->GetComponentDataPtr(_index));
	}

	void LayoutDataStore::IncreaseCapacity()
	{
		ResizeCapacity(static_cast<int>(static_cast<float>(m_data->capacity) * 1.5f));
	}

	void LayoutDataStore::ResizeCapacity(int _capacity)
	{
		assert(_capacity > 0);

		m_data->versions = static_cast<int*>(ResizeArray(m_data->versions, m_data->capacity, _capacity, sizeof(int), alignof(int)));
		for (int i = 0; i < m_data->componentCount; ++i)
		{
			m_data->components[i].ResizeCapacity(_capacity);
		}

		int num = ((m_data->capacity > 0) ? (m_data->capacity - 1) : 0);
		for (int j = num; j < _capacity; ++j)
		{
			m_data->versions[j] = 1;
			SetNextFreeIndex(m_data->components, j, j + 1);
		}

		SetNextFreeIndex(m_data->components, _capacity - 1, -1);
		m_data->capacity = _capacity;
	}

	void* LayoutDataStore::ResizeArray(void* _fromPtr, long _fromCount, long _toCount, long _size, int _align)
	{
		assert(_toCount > 0);
		void* ptr = _aligned_malloc(_size * _toCount, _align);
		assert(ptr != nullptr);
		if (_fromCount <= 0)
		{
			return ptr;
		}

		long num = ((_toCount < _fromCount) ? _toCount : _fromCount);
		long size2 = num * _size;
		memcpy(ptr, _fromPtr, size2);
		_aligned_free(_fromPtr);
		return ptr;
	}

	bool LayoutDataStore::IsValid() const
	{
		return m_data != nullptr;
	}

	int LayoutDataStore::Capacity() const
	{
		return m_data->capacity;
	}

	LayoutDataStore::LayoutDataStore(std::span<const ComponentType> _components, int initialCapacity)
	{
		assert(_components.size() != 0);
		assert(_components[0].size >= 4);
		m_data = static_cast<Data*>(_aligned_malloc(sizeof(Data), alignof(Data)));
		assert(m_data != nullptr);
		memset(m_data, 0, sizeof(Data));
		m_data->componentCount = static_cast<int>(_components.size());
		m_data->components = static_cast<ComponentDataStore*>(_aligned_malloc(sizeof(ComponentDataStore) * _components.size(), alignof(ComponentDataStore)));

		for (int i = 0; i < _components.size(); ++i)
		{
			m_data->components[i] = ComponentDataStore(_components[i].size);
		}

		ResizeCapacity(initialCapacity);
		m_data->nextFreeIndex = 0;
	}

	void LayoutDataStore::Dispose()
	{
		for (int i = 0; i < m_data->componentCount; ++i)
		{
			m_data->components[i].Dispose();
		}

		_aligned_free(m_data->versions);
		_aligned_free(m_data->components);
		m_data = nullptr;
	}

	bool LayoutDataStore::Exists(const LayoutHandle& _handle)
	{
		if (static_cast<uint32_t>(_handle.index) >= static_cast<uint32_t>(m_data->capacity))
		{
			return false;
		}

		return m_data->versions[_handle.index] == _handle.version;
	}

	void* LayoutDataStore::GetComponentDataPtr(int _index, int _componentIndex) const
	{
		return m_data->components[_componentIndex].GetComponentDataPtr(_index);
	}

	LayoutHandle LayoutDataStore::Allocate(uint8_t** _data, int _count)
	{
		int nextFreeIndex = m_data->nextFreeIndex;
		int nextFreeIndex2 = GetNextFreeIndex(m_data->components, nextFreeIndex);
		if (nextFreeIndex2 == -1)
		{
			IncreaseCapacity();
			nextFreeIndex2 = GetNextFreeIndex(m_data->components, nextFreeIndex);
		}

		int version = m_data->versions[nextFreeIndex];
		m_data->nextFreeIndex = nextFreeIndex2;
		assert(m_data->componentCount == _count);
		assert(_data != nullptr);
		for (int i = 0; i < _count; ++i)
		{
			assert(_data[i] != nullptr);
			uint8_t* componentDataPtr = m_data->components[i].GetComponentDataPtr(nextFreeIndex);
			memcpy(componentDataPtr, _data[i], m_data->components[i].size);
		}

		return LayoutHandle(nextFreeIndex, version);
	}

	void LayoutDataStore::Free(const LayoutHandle& _handle)
	{
		if (!Exists(_handle))
		{
			throw std::runtime_error(std::format("Failed to Free handle with Index={} Version={}", _handle.index, _handle.version));
		}

		m_data->versions[_handle.index]++;
		SetNextFreeIndex(m_data->components, _handle.index, m_data->nextFreeIndex);
		m_data->nextFreeIndex = _handle.index;
	}

}