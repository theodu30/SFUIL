#include "../../Headers/SFUIL/System/Properties/BorderProperty.hpp"

namespace sfui
{
	void BorderProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_colorDirty)
		{
			_stream << "border-color: ("
				<< static_cast<int>(m_r) << ","
				<< static_cast<int>(m_g) << ","
				<< static_cast<int>(m_b) << ","
				<< static_cast<int>(m_a) << "); ";
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
		static sf::Color colorCache;
		colorCache.r = m_r;
		colorCache.g = m_g;
		colorCache.b = m_b;
		colorCache.a = m_a;
		return colorCache;
	}

	void BorderProperty::setColor(const sf::Color& _color)
	{
		m_r = _color.r;
		m_g = _color.g;
		m_b = _color.b;
		m_a = _color.a;
		m_colorDirty = true;
	}

	void BorderProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_r = _r;
		m_g = _g;
		m_b = _b;
		m_a = _a;
		m_colorDirty = true;
	}

	void BorderProperty::resetColor()
	{
		m_r = 0;
		m_g = 0;
		m_b = 0;
		m_a = 255;
		m_colorDirty = false;
	}

	void BorderProperty::setColorFromCStr(const char* _colorStr)
	{
		if (_colorStr == nullptr)
		{
			resetColor();
			return;
		}

		std::uint8_t r = 0;
		std::uint8_t g = 0;
		std::uint8_t b = 0;
		std::uint8_t a = 255;

		if (sscanf_s(_colorStr, "(%hhu,%hhu,%hhu,%hhu)", &r, &g, &b, &a) == 4)
		{
			setColor(r, g, b, a);
		}
		else if (sscanf_s(_colorStr, "(%hhu,%hhu,%hhu)", &r, &g, &b) == 3)
		{
			setColor(r, g, b, 255);
		}
		else
		{
			resetColor();
		}
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

	void BorderProperty::setWidthFromCStr(const char* _widthStr)
	{
		if (_widthStr == nullptr)
		{
			resetWidth();
			return;
		}

		float width = 0.f;
		if (sscanf_s(_widthStr, "%f", &width) == 1)
		{
			setWidth(width);
		}
		else
		{
			resetWidth();
		}
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

	void BorderProperty::setRadiusFromCStr(const char* _radiusStr)
	{
		if (_radiusStr == nullptr)
		{
			resetRadius();
			return;
		}

		float radius = 0.f;
		if (sscanf_s(_radiusStr, "%f", &radius) == 1)
		{
			setRadius(radius);
		}
		else
		{
			resetRadius();
		}
	}

}
