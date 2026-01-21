#pragma once

#include "../../Exports.hpp"
#include "../StyleValue.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	class StyleColor : public StyleValue<sf::Color>
	{
	private:
		sf::Color m_value;
		StyleKeyword m_keyword;

		StyleColor(sf::Color _value, StyleKeyword _keyword);

	public:
		const sf::Color getValue() const override;
		void setValue(const sf::Color _value) override;

		StyleKeyword getKeyword() const override;
		void setKeyword(StyleKeyword _keyword) override;

		StyleColor(sf::Color _value);
		StyleColor(StyleKeyword _keyword);
	};
}