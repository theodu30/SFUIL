#include "../Headers/SFUIL/System/PanelAnchor.hpp"

namespace sfui
{
	namespace Alignments
	{
		const Alignment UpperLeft = { VerticalAlignment::Upper, HorizontalAlignment::Left };
		const Alignment UpperCenter = { VerticalAlignment::Upper, HorizontalAlignment::Center };
		const Alignment UpperRight = { VerticalAlignment::Upper, HorizontalAlignment::Right };
		const Alignment MiddleLeft = { VerticalAlignment::Middle, HorizontalAlignment::Left };
		const Alignment MiddleCenter = { VerticalAlignment::Middle, HorizontalAlignment::Center };
		const Alignment MiddleRight = { VerticalAlignment::Middle, HorizontalAlignment::Right };
		const Alignment LowerLeft = { VerticalAlignment::Lower, HorizontalAlignment::Left };
		const Alignment LowerCenter = { VerticalAlignment::Lower, HorizontalAlignment::Center };
		const Alignment LowerRight = { VerticalAlignment::Lower, HorizontalAlignment::Right };

		sf::Vector2f PositionFromAlignment(const Alignment _alignment, const sf::Vector2f _parentSize, const sf::Vector2f _childSize)
		{
			sf::Vector2f toReturn;

			switch (_alignment.vertical)
			{
			case VerticalAlignment::Upper: toReturn.y = 0.f; break;
			case VerticalAlignment::Middle: toReturn.y = (_parentSize.y - _childSize.y) / 2.f; break;
			case VerticalAlignment::Lower: toReturn.y = _parentSize.y - _childSize.y; break;
			}

			switch (_alignment.horizontal)
			{
			case HorizontalAlignment::Left: toReturn.x = 0.f; break;
			case HorizontalAlignment::Center: toReturn.x = (_parentSize.x - _childSize.x) / 2.f; break;
			case HorizontalAlignment::Right: toReturn.x = _parentSize.x - _childSize.x; break;
			}

			return toReturn;
		}
	}
}
