#include <cmath>
#include <limits>
#include "../Headers/SFUIL/System/Layout/LayoutValue.hpp"

namespace sfui
{
	LayoutValue::LayoutValue() : m_value(0.f), m_unit(LayoutUnit::Undefined)
	{
	}

	LayoutValue::LayoutValue(float _value)
	{
		*this = Point(_value);
	}

	LayoutUnit LayoutValue::getUnit() const
	{
		return m_unit;
	}

	float LayoutValue::getValue() const
	{
		return m_value;
	}

	LayoutValue LayoutValue::Point(float _value)
	{
		LayoutValue result;
		result.m_value = _value;
		result.m_unit = (!std::isnan(_value) ? LayoutUnit::Point : LayoutUnit::Undefined);
		return result;
	}

	LayoutValue LayoutValue::Undefined()
	{
		LayoutValue result;
		result.m_value = NAN;
		result.m_unit = LayoutUnit::Undefined;
		return result;
	}

	LayoutValue LayoutValue::Auto()
	{
		LayoutValue result;
		result.m_value = NAN;
		result.m_unit = LayoutUnit::Auto;
		return result;
	}

	LayoutValue LayoutValue::Percent(float _value)
	{
		LayoutValue result;
		result.m_value = _value;
		result.m_unit = (!std::isnan(_value) ? LayoutUnit::Percent : LayoutUnit::Undefined);
		return result;
	}

	bool LayoutValue::operator==(const LayoutValue& _value)
	{
		return m_unit == _value.m_unit && (std::abs(m_value - _value.m_value) < FLT_EPSILON);
	}

	bool LayoutValue::operator!=(const LayoutValue& _value)
	{
		return !(*this == _value);
	}

	LayoutValue::LayoutValue(const LayoutValue& _other)
	{
		m_unit = _other.m_unit;
		m_value = _other.m_value;
	}

	LayoutValue& LayoutValue::operator=(const LayoutValue& _other)
	{
		this->m_unit = _other.m_unit;
		this->m_value = _other.m_value;

		return *this;
	}

	LayoutValue::LayoutValue(LayoutValue&& _other) noexcept
	{
		m_unit = _other.m_unit;
		m_value = _other.m_value;

		_other.m_value = 0.f;
		_other.m_unit = LayoutUnit::Undefined;
	}

	LayoutValue& LayoutValue::operator=(LayoutValue&& _other) noexcept
	{
		this->m_unit = _other.m_unit;
		this->m_value = _other.m_value;

		_other.m_value = 0.f;
		_other.m_unit = LayoutUnit::Undefined;

		return *this;
	}

}