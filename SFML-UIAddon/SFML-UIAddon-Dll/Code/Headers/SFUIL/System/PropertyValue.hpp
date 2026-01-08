#pragma once

#include "Exports.hpp"
#include <SFML/System/Angle.inl>

namespace sfui
{
	template<typename T>
	class SFUIL_API PropertyValue
	{
	private:
		T m_value;
		T m_defaultValue;
		bool m_dirty = false;

	public:
		PropertyValue(const T& _value);

		void set(const T& _value);
		const T& get() const;

		void reset();

	private:
		void setDefault(const T& _value);
	};

}

#include "PropertyValue.inl"