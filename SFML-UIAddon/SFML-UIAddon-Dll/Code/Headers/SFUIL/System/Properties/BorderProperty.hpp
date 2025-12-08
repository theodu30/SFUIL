#pragma once

#include "Property.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	class SFUIL_API BorderProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		[[nodiscard]] const sf::Color& getColor() const;
		void setColor(const sf::Color& _color);
		void setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a = 255);
		void resetColor();

		[[nodiscard]] const float& getWidth() const;
		void setWidth(float _width);
		void resetWidth();

		[[nodiscard]] const float& getRadius() const;
		void setRadius(float _radius);
		void resetRadius();

	private:
		sf::Color m_color = sf::Color::Black;
		bool m_colorDirty = false;
		float m_width = 0.f;
		bool m_widthDirty = false;
		float m_radius = 0.f;
		bool m_radiusDirty = false;
	};
}