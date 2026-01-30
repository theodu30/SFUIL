#pragma once

#include "../Exports.hpp"

namespace sfui
{
	template<typename T>
	class StyleDataRef
	{
	private:
		class RefCounted
		{
		private:
			int m_refCount;

		public:
			T value;

			RefCounted()
			{
				value = T();
				m_refCount = 1;
			}

			int getRefCount()
			{
				return m_refCount;
			}

			void Acquire()
			{
				++m_refCount;
			}

			void Release()
			{
				--m_refCount;
			}
		};

		RefCounted m_ref;

	public:

		int getRefCount()
		{
			return m_ref.getRefCount();
		}

		StyleDataRef<T>& Acquire()
		{
			m_ref.Acquire();
			return *this;
		}

		void Release()
		{
			m_ref.Release();
		}

		const T& Read() const
		{
			return m_ref.value;
		}

		T& Write()
		{
			if (m_ref.getRefCount() == 1)
			{
				return m_ref.value;
			}

			RefCounted ref = m_ref;
			m_ref = RefCounted();
			m_ref.value = ref.value;
			ref.Release();
			return m_ref.value;
		}

		static StyleDataRef<T> Create()
		{
			StyleDataRef<T> result;
			result.m_ref = RefCounted();
			return result;
		}
	};
}