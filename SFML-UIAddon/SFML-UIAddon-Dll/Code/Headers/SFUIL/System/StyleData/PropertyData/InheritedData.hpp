#pragma once

#include "../../Exports.hpp"
#include "../../Length.hpp"
#include "../PropertyData/StyleEnumList.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>

namespace sfui
{
	class SFUIL_API InheritedData
	{
	public:
		sf::Font textFont;
		Length fontSize;
		
		sf::Color textColor;
		VisibilityEnum visibility = (VisibilityEnum)0;
		FontStyleEnum fontStyle = (FontStyleEnum)0;
		TextAlignEnum textAlign = (TextAlignEnum)0;
	};
}
