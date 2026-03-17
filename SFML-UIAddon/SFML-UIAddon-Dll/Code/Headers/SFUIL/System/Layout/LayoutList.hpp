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

	public:
		class Enumerator : public IEnumerator<T>, public IDisposable
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
	};

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
		if (_index >= m_data->count)
		{
			throw std::out_of_range();
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
		m_data = _aligned_malloc(sizeof(Data), 16);
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
		if (_index >= m_data->count)
		{
			throw std::out_of_range();
		}

		if (m_data->capacity == m_data->count)
		{
			IncreaseCapacity();
		}

		if (_index < m_data->count)
		{
			memmove(m_data->values + _index + 1, m_data->values + _index), sizeof(T)* (m_data->count - _index));
		}
	}

}