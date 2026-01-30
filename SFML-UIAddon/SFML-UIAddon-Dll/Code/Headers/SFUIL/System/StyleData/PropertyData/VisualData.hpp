#pragma once

#include "../../Exports.hpp"
#include "../../Datas/BackgroundPosition.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sfui
{
	class SFUIL_API VisualData
	{
	public:
		sf::Color backgroundColor;

		BackgroundPosition backgroundPositionX;
		BackgroundPosition BackgroundPositionY;

		bool repeat;
	};
}
