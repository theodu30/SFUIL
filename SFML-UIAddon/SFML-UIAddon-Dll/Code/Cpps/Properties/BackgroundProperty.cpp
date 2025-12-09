#include "../../Headers/SFUIL/System/Properties/BackgroundProperty.hpp"

namespace sfui
{
	void BackgroundProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_colorDirty)
		{
			_stream << "background-color: ("
				<< static_cast<int>(m_r) << ","
				<< static_cast<int>(m_g) << ","
				<< static_cast<int>(m_b) << ","
				<< static_cast<int>(m_a) << "); ";
		}
	}

	const sf::Color& BackgroundProperty::getColor() const
	{
		static sf::Color colorCache;
		colorCache.r = m_r;
		colorCache.g = m_g;
		colorCache.b = m_b;
		colorCache.a = m_a;
		return colorCache;
	}

	void BackgroundProperty::setColor(const sf::Color& _color)
	{
		m_r = _color.r;
		m_g = _color.g;
		m_b = _color.b;
		m_a = _color.a;
		m_colorDirty = true;
	}

	void BackgroundProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_r = _r;
		m_g = _g;
		m_b = _b;
		m_a = _a;
		m_colorDirty = true;
	}

	void BackgroundProperty::resetColor()
	{
		m_r = 0;
		m_g = 0;
		m_b = 0;
		m_a = 0;
		m_colorDirty = false;
	}
}
