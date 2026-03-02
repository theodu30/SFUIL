#include "../Headers/SFUIL/System/Length.hpp"

namespace sfui
{
	constexpr Length::Length(float _value, Unit _unit) : m_value(_value), m_unit(_unit)
	{
	}

	constexpr Length::Length() : m_value(0.f), m_unit(Unit::Pixel)
	{
	}

	constexpr Length::Length(const Length& _other)
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;
	}

	constexpr Length& Length::operator=(const Length& _other)
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;

		return *this;
	}

	constexpr Length::Length(Length&& _other) noexcept
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;

		_other.m_value = 0.f;
		_other.m_unit = Unit::Pixel;
	}

	constexpr Length& Length::operator=(Length&& _other) noexcept
	{
		this->m_value = _other.m_value;
		this->m_unit = _other.m_unit;

		_other.m_value = 0.f;
		_other.m_unit = Unit::Pixel;

		return *this;
	}

	constexpr Length::Length(float _value) : m_value(_value), m_unit(Unit::Pixel)
	{
	}

	constexpr Length::Length(float _value, LengthUnit _unit) : m_value(_value)
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

	namespace Literals
	{
		sfui::Length operator""_px(long double _value)
		{
			return sfui::Length::Pixels(static_cast<float>(_value));
		}

		sfui::Length operator""_px(unsigned long long _value)
		{
			return sfui::Length::Pixels(static_cast<float>(_value));
		}

		sfui::Length operator""_pct(long double _value)
		{
			return sfui::Length::Percent(static_cast<float>(_value));
		}

		sfui::Length operator""_pct(unsigned long long _value)
		{
			return sfui::Length::Percent(static_cast<float>(_value));
		}

		sfui::Length operator""_em(long double _value)
		{
			return sfui::Length::Em(static_cast<float>(_value));
		}

		sfui::Length operator""_em(unsigned long long _value)
		{
			return sfui::Length::Em(static_cast<float>(_value));
		}

		sfui::Length operator""_rem(long double _value)
		{
			return sfui::Length::Rem(static_cast<float>(_value));
		}

		sfui::Length operator""_rem(unsigned long long _value)
		{
			return sfui::Length::Rem(static_cast<float>(_value));
		}

		sfui::Length operator""_vw(long double _value)
		{
			return sfui::Length::Vw(static_cast<float>(_value));
		}

		sfui::Length operator""_vw(unsigned long long _value)
		{
			return sfui::Length::Vw(static_cast<float>(_value));
		}

		sfui::Length operator""_vh(long double _value)
		{
			return sfui::Length::Vh(static_cast<float>(_value));
		}

		sfui::Length operator""_vh(unsigned long long _value)
		{
			return sfui::Length::Vh(static_cast<float>(_value));
		}

	}

}
