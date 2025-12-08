#include "../../Headers/SFUIL/System/Properties/BorderProperty.hpp"

namespace sfui
{
	void BorderProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_colorDirty)
		{
			_stream << "border-color: ("
				<< static_cast<int>(m_color.r) << ","
				<< static_cast<int>(m_color.g) << ","
				<< static_cast<int>(m_color.b) << ","
				<< static_cast<int>(m_color.a) << "); ";
		}

		if (m_widthDirty)
		{
			_stream << "border-width: " << m_width << "; ";
		}

		if (m_radiusDirty)
		{
			_stream << "border-radius: " << m_radius << "; ";
		}
	}

	const sf::Color& BorderProperty::getColor() const
	{
		return m_color;
	}

	void BorderProperty::setColor(const sf::Color& _color)
	{
		m_color = _color;
		m_colorDirty = true;
	}

	void BorderProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
		m_color.a = _a;
		m_colorDirty = true;
	}

	void BorderProperty::resetColor()
	{
		m_color = sf::Color::Black;
		m_colorDirty = false;
	}

	const float& BorderProperty::getWidth() const
	{
		return m_width;
	}

	void BorderProperty::setWidth(float _width)
	{
		m_width = _width;
		m_widthDirty = true;
	}

	void BorderProperty::resetWidth()
	{
		m_width = 0.f;
		m_widthDirty = false;
	}

	const float& BorderProperty::getRadius() const
	{
		return m_radius;
	}

	void BorderProperty::setRadius(float _radius)
	{
		m_radius = _radius;
		m_radiusDirty = true;
	}

	void BorderProperty::resetRadius()
	{
		m_radius = 0.f;
		m_radiusDirty = false;
	}
}
