#include "../Headers/SFUIL/System/StyleData/StyleValues/StyleInt.hpp"

namespace sfui
{
	StyleInt::StyleInt(int _value, StyleKeyword _keyword) : m_value(_value), m_keyword(_keyword)
	{
	}

	const int StyleInt::getValue() const
	{
		return (m_keyword == StyleKeyword::Undefined) ? m_value : 0;
	}

	void StyleInt::setValue(const int _value)
	{
		m_value = _value;
		m_keyword = StyleKeyword::Undefined;
	}

	StyleKeyword StyleInt::getKeyword() const
	{
		return m_keyword;
	}

	void StyleInt::setKeyword(StyleKeyword _keyword)
	{
		m_keyword = _keyword;
	}

	StyleInt::StyleInt(int _value) : StyleInt(_value, StyleKeyword::Undefined)
	{
	}

	StyleInt::StyleInt(StyleKeyword _keyword) : StyleInt(0, _keyword)
	{
	}

}
