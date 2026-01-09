#include "../Headers/SFUIL/System/Length.hpp"

namespace sfui
{
	Length::Length(float _value, Unit _unit) : m_value(_value), m_unit(_unit)
	{
	}

	Length::Length() : m_value(0.f), m_unit(Unit::Pixel)
	{
	}

	Length::Length(const Length& _other)
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;
	}

	Length& Length::operator=(const Length& _other)
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;

		return *this;
	}

	Length::Length(Length&& _other) noexcept
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;

		_other.m_value = 0.f;
		_other.m_unit = Unit::Pixel;
	}

	Length& Length::operator=(Length&& _other) noexcept
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;

		_other.m_value = 0.f;
		_other.m_unit = Unit::Pixel;

		return *this;
	}

	Length::Length(float _value) : m_value(_value), m_unit(Unit::Pixel)
	{
	}

	Length::Length(float _value, LengthUnit _unit) : m_value(_value)
	{
		switch (_unit)
		{
		case LengthUnit::Percent:
			m_unit = Unit::Percent;
			break;

		case LengthUnit::Pixel:
		default: 
			m_unit = Unit::Pixel;
			break;
		}
	}

	bool Length::isAuto() const
	{
		return m_unit == Unit::Auto;
	}

	bool Length::isNone() const
	{
		return m_unit == Unit::None;
	}

	float Length::getValue() const
	{
		return m_value;
	}

	void Length::setValue(float _value)
	{
		m_value = _value;
	}

	LengthUnit Length::getUnit() const
	{
		switch (m_unit)
		{
		case Unit::Pixel:
			return LengthUnit::Pixel;
		case Unit::Percent:
			return LengthUnit::Percent;
		default:
			throw "Unknown unit";
		}
	}

	void Length::setUnit(LengthUnit _unit)
	{
		switch (_unit)
		{
		case LengthUnit::Percent:
			m_unit = Unit::Percent;
			break;

		case LengthUnit::Pixel:
		default:
			m_unit = Unit::Pixel;
			break;
		}
	}

	Length Length::Pixels(float _value)
	{
		return Length(_value, Unit::Pixel);
	}

	Length Length::Percent(float _value)
	{
		return Length(_value, Unit::Percent);
	}

	Length Length::Em(float _value)
	{
		return Length(_value, Unit::Em);
	}

	Length Length::Rem(float _value)
	{
		return Length(_value, Unit::Rem);
	}

	Length Length::Vw(float _value)
	{
		return Length(_value, Unit::Vw);
	}

	Length Length::Vh(float _value)
	{
		return Length(_value, Unit::Vh);
	}

	Length Length::Auto()
	{
		return Length(0.f, Unit::Auto);
	}

	Length Length::None()
	{
		return Length(0.f, Unit::None);
	}

}
