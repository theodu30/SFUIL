#pragma once

#include "Property.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	class SFUIL_API BackgroundProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		[[nodiscard]] const sf::Color& getColor() const;
		void setColor(const sf::Color& _color);
		void setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a = 255);
		void resetColor();

	private:
		std::uint8_t m_r = 0;
		std::uint8_t m_g = 0;
		std::uint8_t m_b = 0;
		std::uint8_t m_a = 0;
		bool m_colorDirty = false;
	};
}