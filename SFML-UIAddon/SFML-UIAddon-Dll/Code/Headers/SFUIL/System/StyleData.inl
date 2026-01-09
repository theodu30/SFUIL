#include "StyleData.hpp"

namespace sfui
{
	template<typename T>
	StyleData<T>::RefCount::RefCount() : m_refCount(1)
	{
	}

	template<typename T>
	int StyleData<T>::RefCount::getRefCount()
	{
		return m_refCount;
	}

	template<typename T>
	void StyleData<T>::RefCount::call()
	{
		m_refCount++;
	}

	template<typename T>
	void StyleData<T>::RefCount::release()
	{
		m_refCount--;
	}

	template<typename T>
	StyleData<T>::RefCount StyleData<T>::RefCount::copy()
	{
		RefCount ref;
		ref.value = value;
		return ref;
	}

	template<typename T>
	int StyleData<T>::getRefCount()
	{
		return m_ref.getRefCount();
	}

	template<typename T>
	StyleData<T> StyleData<T>::call()
	{
		m_ref.call();
		return *this;
	}

	template<typename T>
	void StyleData<T>::release()
	{
		m_ref.release();
		m_ref = RefCount();
	}

	template<typename T>
	const T& StyleData<T>::read()
	{
		return m_ref.value;
	}

	template<typename T>
	T& StyleData<T>::write()
	{
		if (m_ref.getRefCount() == 1)
		{
			return m_ref.value;
		}

		RefCount ref = m_ref;
		m_ref = m_ref.copy();
		ref.release();

		return m_ref.value;
	}

	template<typename T>
	StyleData<T> StyleData<T>::create()
	{
		StyleData<T> result;
		result.m_ref = RefCount();
		return result;
	}

}