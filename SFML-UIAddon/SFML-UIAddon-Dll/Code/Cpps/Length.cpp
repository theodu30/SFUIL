#include "../Headers/SFUIL/System/Length.hpp"

namespace sfui
{

	Length::Length(float _value) : m_value(_value), m_unit(LengthUnit::Pixel)
	{
	}

	Length::Length(float _value, LengthUnit _unit) : m_value(_value), m_unit(_unit)
	{
	}

	void Length::set(float _value, LengthUnit _unit)
	{
		m_value = _value;
		m_unit = _unit;
	}

	void Length::setDefault(float _value, LengthUnit _unit)
	{
		m_defaultValue = _value;
		m_defaultUnit = _unit;
	}

	float Length::toPixels(const LengthContext& _ctx)
	{
		switch (m_unit)
		{
		case LengthUnit::Pixel:
			return m_value;
		case LengthUnit::Percent:
			return m_value * _ctx.parentSize * 0.01f;
		case LengthUnit::Em:
			return m_value * _ctx.fontSize * 0.01f;
		case LengthUnit::Rem:
			return m_value * _ctx.rootFontSize * 0.01f;
		case LengthUnit::Vw:
			return m_value * _ctx.viewportWidth * 0.01f;
		case LengthUnit::Vh:
			return m_value * _ctx.viewportHeight * 0.01f;

		case LengthUnit::Auto:
		case LengthUnit::Initial:
		case LengthUnit::None:
		default:
			return 0.f;
		}
	}

	bool Length::isResolvable()
	{
		return m_unit == LengthUnit::Pixel
			|| m_unit == LengthUnit::Percent
			|| m_unit == LengthUnit::Em
			|| m_unit == LengthUnit::Rem
			|| m_unit == LengthUnit::Vw
			|| m_unit == LengthUnit::Vh;
	}

	Length Length::px(float _value)
	{
		return Length(_value, LengthUnit::Pixel);
	}

	Length Length::percent(float _value)
	{
		return Length(_value, LengthUnit::Percent);
	}

	Length Length::em(float _value)
	{
		return Length(_value, LengthUnit::Em);
	}

	Length Length::rem(float _value)
	{
		return Length(_value, LengthUnit::Rem);
	}

	Length Length::vw(float _value)
	{
		return Length(_value, LengthUnit::Vw);
	}

	Length Length::vh(float _value)
	{
		return Length(_value, LengthUnit::Vh);
	}

}
