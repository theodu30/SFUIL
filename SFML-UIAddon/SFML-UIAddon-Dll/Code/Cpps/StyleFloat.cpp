#include "../Headers/SFUIL/System/StyleData/StyleValues/StyleFloat.hpp"

namespace sfui
{
	StyleFloat::StyleFloat(float _value, StyleKeyword _keyword) : m_value(_value), m_keyword(_keyword)
	{
	}

	const float StyleFloat::getValue() const
	{
		return (m_keyword == StyleKeyword::Undefined) ? m_value : 0.f;
	}

	void StyleFloat::setValue(const float _value)
	{
		m_value = _value;
		m_keyword = StyleKeyword::Undefined;
	}

	StyleKeyword StyleFloat::getKeyword() const
	{
		return m_keyword;
	}

	void StyleFloat::setKeyword(StyleKeyword _keyword)
	{
		m_keyword = _keyword;
	}

	StyleFloat::StyleFloat(float _value) : StyleFloat(_value, StyleKeyword::Undefined)
	{
	}

	StyleFloat::StyleFloat(StyleKeyword _keyword) : StyleFloat(0.f, _keyword)
	{
	}

}
