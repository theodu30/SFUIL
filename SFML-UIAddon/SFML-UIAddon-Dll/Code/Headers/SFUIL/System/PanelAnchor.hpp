#pragma once

#include "Exports.hpp"

#include <SFML/System/Vector2.hpp>

namespace sfui
{
	enum class VerticalAlignment : char
	{
		Upper,
		Middle,
		Lower
	};

	enum class HorizontalAlignment : char
	{
		Left,
		Center,
		Right
	};

	struct SFUIL_API Alignment
	{
		VerticalAlignment vertical = VerticalAlignment::Upper;
		HorizontalAlignment horizontal = HorizontalAlignment::Left;
	};

	namespace Alignments
	{
		extern SFUIL_API const Alignment UpperLeft;
		extern SFUIL_API const Alignment UpperCenter;
		extern SFUIL_API const Alignment UpperRight;
		extern SFUIL_API const Alignment MiddleLeft;
		extern SFUIL_API const Alignment MiddleCenter;
		extern SFUIL_API const Alignment MiddleRight;
		extern SFUIL_API const Alignment LowerLeft;
		extern SFUIL_API const Alignment LowerCenter;
		extern SFUIL_API const Alignment LowerRight;

		SFUIL_API sf::Vector2f PositionFromAlignment(const Alignment _alignment, const sf::Vector2f _parentSize, const sf::Vector2f _childSize);
	}
}