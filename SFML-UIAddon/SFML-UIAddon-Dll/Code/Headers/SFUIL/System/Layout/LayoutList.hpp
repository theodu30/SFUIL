#pragma once

#include "../Interfaces/IDisposable.hpp"
#include "../Interfaces/IEnumerator.hpp"
#include <stdexcept>
#include <cassert>

namespace sfui
{
	template <typename T>
	class LayoutList : public IDisposable
	{
	private:
		struct Data
		{
			int capacity = 0;
			int count = 0;
			T* values = nullptr;
		};

		Data* m_data;

		void IncreaseCapacity();

		void EnsureCapacity(int _capacity);

		void ResizeCapacity(int _capacity);

		static void* ResizeArray(void* _fromPtr, long _fromCount, long _toCount, long _size, int _align);

	public:
		class Enumerator : public IEnumerator<T>
		{
		private:
			LayoutList<T> m_list;
			int m_index;
			T m_current;

		public:
			T Current() const override;

			Enumerator(LayoutList<T> _list);

			void Dispose() override;

			bool MoveNext() override;

			void Reset() override;
		};

		int Count();

		bool IsCreated();

		T& operator[](int _index);

		LayoutList();

		LayoutList(int _initialCapacity);

		void Dispose() override;

		void Insert(int _index, T _value);

		int IndexOf(T _value);

		void RemoveAt(int _index);

		void Clear();

		Enumerator GetEnumerator();
	};

	template<typename T>
	inline void LayoutList<T>::IncreaseCapacity()
	{
		EnsureCapacity(m_data->capacity * 2);
	}

	template<typename T>
	inline void LayoutList<T>::EnsureCapacity(int _capacity)
	{
		if (_capacity > m_data->capacity)
		{
			ResizeCapacity(_capacity);
		}
	}

	template<typename T>
	inline void LayoutList<T>::ResizeCapacity(int _capacity)
	{
		assert(_capacity > 0);
		m_data->values = reinterpret_cast<T*>(ResizeArray(m_data->values, m_data->capacity, _capacity, sizeof(T), 16));
		m_data->capacity = _capacity;
	}

	template<typename T>
	void* LayoutList<T>::ResizeArray(void* _fromPtr, long _fromCount, long _toCount, long _size, int _align)
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

	template<typename T>
	inline T LayoutList<T>::Enumerator::Current() const
	{
		return m_current;
	}

	template<typename T>
	inline LayoutList<T>::Enumerator::Enumerator(LayoutList<T> _list)
	{
		m_list = m_list;
		m_index = 0;
		m_current = T{};
	}

	template<typename T>
	inline void LayoutList<T>::Enumerator::Dispose()
	{
	}

	template<typename T>
	inline bool LayoutList<T>::Enumerator::MoveNext()
	{
		if (!m_list.IsCreated())
		{
			m_current = T{};
			return false;
		}

		if (m_index >= m_list.Count())
		{
			m_current = T{};
			return false;
		}

		m_current = m_list[m_index];
		++m_index;
		return true;
	}

	template<typename T>
	inline void LayoutList<T>::Enumerator::Reset()
	{
		m_index = 0;
	}

	template<typename T>
	inline int LayoutList<T>::Count()
	{
		return m_data->count;
	}

	template<typename T>
	inline bool LayoutList<T>::IsCreated()
	{
		return m_data != nullptr;
	}

	template<typename T>
	T& LayoutList<T>::operator[](int _index)
	{
		if (static_cast<unsigned int>(_index) >= static_cast<unsigned int>(m_data->count))
		{
			throw std::out_of_range("index");
		}
		return m_data->values[_index];
	}

	template<typename T>
	inline LayoutList<T>::LayoutList()
	{
		m_data = nullptr;
	}

	template<typename T>
	inline LayoutList<T>::LayoutList(int _initialCapacity)
	{
		m_data = reinterpret_cast<Data*>(_aligned_malloc(sizeof(Data), 16));
		assert(m_data != nullptr);
		*m_data = Data{};
		ResizeCapacity(_initialCapacity);
	}

	template<typename T>
	inline void LayoutList<T>::Dispose()
	{
		if (m_data != nullptr)
		{
			if (m_data->values != nullptr)
			{
				_aligned_free(m_data->values);
			}

			_aligned_free(m_data);
			m_data = nullptr;
		}
	}

	template<typename T>
	inline void LayoutList<T>::Insert(int _index, T _value)
	{
		if (static_cast<unsigned int>(_index) >= static_cast<unsigned int>(m_data->count))
		{
			throw std::out_of_range("index");
		}

		if (m_data->capacity == m_data->count)
		{
			IncreaseCapacity();
		}

		if (_index < m_data->count)
		{
			memmove(m_data->values + _index + 1, m_data->values + _index, sizeof(T)* (m_data->count - _index));
		}
	}

	template<typename T>
	inline int LayoutList<T>::IndexOf(T _value)
	{
		int count = m_data->count;
		T* ptr = &_value;
		T* ptr2 = m_data->values;
		int num = sizeof(T);
		for (int num2 = 0; num2 < count; ++num2)
		{
			if (memcmp(ptr2, ptr, num) == 0)
			{
				return num2;
			}

			ptr2++;
		}

		return -1;
	}

	template<typename T>
	inline void LayoutList<T>::RemoveAt(int _index)
	{
		if (static_cast<unsigned int>(_index) >= static_cast<unsigned int>(m_data->count))
		{
			throw std::out_of_range("index");
		}

		m_data->count--;
		memmove(m_data->values + _index, m_data->values + _index + 1, sizeof(T) * (m_data->count - _index));
		m_data->values[m_data->count] = T{};
	}

	template<typename T>
	inline void LayoutList<T>::Clear()
	{
		m_data->count = 0;
	}

	template<typename T>
	inline LayoutList<T>::Enumerator LayoutList<T>::GetEnumerator()
	{
		return Enumerator(*this);
	}

}