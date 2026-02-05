#pragma once

#include "../../Exports.hpp"
#include "../../Length.hpp"
#include "../../Datas/BackgroundPosition.hpp"
#include "../../Datas/BackgroundSize.hpp"
#include <SFML/Graphics/Color.hpp>
#include <string>

namespace sfui
{
	class SFUIL_API VisualData
	{
	public:
		std::string textureKey = "";

		BackgroundPosition backgroundPositionX;
		BackgroundPosition backgroundPositionY;

		BackgroundSize backgroundSize;
		float opacity = 1.f;

		Length borderRadius;

		sf::Color backgroundColor;
		sf::Color borderColor;

		sf::Color backgroundImageTint;

		bool backgroundRepeat = false;
		bool backgroundSmooth = false;
	};
}
