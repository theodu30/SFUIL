#include "../Headers/SFUIL/System/Layout/LayoutDataStore.hpp"
#include <cstdlib>

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
			m_chunks = (Chunk*)ResizeArray(m_chunks, chunkCount, num, sizeof(Chunk), alignof(Chunk));
			for (int i = 0; i < num; ++i)
			{
				m_chunks[i] = Chunk
				{
					reinterpret_cast<uint8_t*>(_aligned_malloc(32768u, 4))
				};
			}
		}
	}

}