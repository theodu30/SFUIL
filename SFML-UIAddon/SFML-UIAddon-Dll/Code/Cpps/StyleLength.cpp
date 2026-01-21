#include "../Headers/SFUIL/System/StyleData/StyleValues/StyleLength.hpp"

namespace sfui
{
	StyleLength::StyleLength(Length _value, StyleKeyword _keyword) : m_value(_value), m_keyword(_keyword)
	{
		if (_value.isAuto())
		{
			m_keyword = StyleKeyword::Auto;
		}
		else if (_value.isNone())
		{
			m_keyword = StyleKeyword::None;
		}
	}

	const Length StyleLength::getValue() const
	{
		if (m_keyword == StyleKeyword::Auto || m_keyword == StyleKeyword::None || m_keyword == StyleKeyword::Undefined)
		{
			return m_value;
		}

		return Length();
	}

	void StyleLength::setValue(const Length _value)
	{
		if (_value.isAuto())
		{
			m_keyword = StyleKeyword::Auto;
		}
		else if (_value.isNone())
		{
			m_keyword = StyleKeyword::None;
		}
		else
		{
			m_keyword = StyleKeyword::Undefined;
		}

		m_value = _value;
	}

	StyleKeyword StyleLength::getKeyword() const
	{
		return m_keyword;
	}

	void StyleLength::setKeyword(StyleKeyword _keyword)
	{
		m_keyword = _keyword;
	}

	StyleLength::StyleLength(float _value) : StyleLength(Length(_value, LengthUnit::Pixel), StyleKeyword::Undefined)
	{
	}

	StyleLength::StyleLength(Length _value) : StyleLength(_value, StyleKeyword::Undefined)
	{
	}

	StyleLength::StyleLength(StyleKeyword _keyword) : StyleLength(Length(), _keyword)
	{
	}

}