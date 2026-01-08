#include "PropertyValue.hpp"

namespace sfui
{
	template<typename T>
	inline PropertyValue<T>::PropertyValue(const T& _value)
	{
		m_value = _value;
		m_defaultValue = _value;
	}

	template<typename T>
	inline void PropertyValue<T>::set(const T& _value)
	{
		m_value = _value;
		m_dirty = true;
	}

	template<typename T>
	inline const T& PropertyValue<T>::get() const
	{
		return m_value;
	}

	template<typename T>
	inline void PropertyValue<T>::reset()
	{
		m_value = m_defaultValue;
		m_dirty = true;
	}

	template<typename T>
	inline void PropertyValue<T>::setDefault(const T& _value)
	{
		m_defaultValue = _value;
	}

}