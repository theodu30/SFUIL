#pragma once
#include <stdexcept>

namespace sfui
{
	template <typename T, int N>
	struct FixedBuffer
	{
		static_assert(N > 0);
		static constexpr int Length = N;

		T& operator[](int _index)
		{
			if (_index < 0 || _index >= N)
			{
				throw std::out_of_range("index");
			}

			return m_data[_index];
		}

		const T& operator[](int _index) const
		{
			if (_index < 0 || _index >= N)
			{
				throw std::out_of_range("index");
			}

			return m_data[_index];
		}

	private:
		T m_data[N];
	};
}