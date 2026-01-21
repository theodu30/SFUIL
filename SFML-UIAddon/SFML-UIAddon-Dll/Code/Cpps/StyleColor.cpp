#include "../Headers/SFUIL/System/StyleData/StyleValues/StyleColor.hpp"

namespace sfui
{
	StyleColor::StyleColor(sf::Color _value, StyleKeyword _keyword) : m_value(_value), m_keyword(_keyword)
	{
	}

	const sf::Color StyleColor::getValue() const
	{
		return (m_keyword == StyleKeyword::Undefined) ? m_value : sf::Color();
	}

	void StyleColor::setValue(const sf::Color _value)
	{
		m_value = _value;
		m_keyword = StyleKeyword::Undefined;
	}

	StyleKeyword StyleColor::getKeyword() const
	{
		return m_keyword;
	}

	void StyleColor::setKeyword(StyleKeyword _keyword)
	{
		m_keyword = _keyword;
	}

	StyleColor::StyleColor(sf::Color _value) : StyleColor(_value, StyleKeyword::Undefined)
	{
	}

	StyleColor::StyleColor(StyleKeyword _keyword) : StyleColor(sf::Color(), _keyword)
	{
	}

}