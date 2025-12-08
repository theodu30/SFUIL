#include "../../Headers/SFUIL/System/Properties/BackgroundProperty.hpp"

namespace sfui
{
	void BackgroundProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_colorDirty)
		{
			_stream << "background-color: ("
				<< static_cast<int>(m_color.r) << ","
				<< static_cast<int>(m_color.g) << ","
				<< static_cast<int>(m_color.b) << ","
				<< static_cast<int>(m_color.a) << "); ";
		}
	}

	const sf::Color& BackgroundProperty::getColor() const
	{
		return m_color;
	}

	void BackgroundProperty::setColor(const sf::Color& _color)
	{
		m_color = _color;
		m_colorDirty = true;
	}

	void BackgroundProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
		m_color.a = _a;
		m_colorDirty = true;
	}

	void BackgroundProperty::resetColor()
	{
		m_color = sf::Color::Transparent;
		m_colorDirty = false;
	}
}
