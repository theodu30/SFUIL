#pragma once

#include "Exports.hpp"
#include "Properties.hpp"
#include <SFML/Graphics/Transformable.hpp>

namespace sfui
{
	class SFUIL_API UIPropUtils
	{
	public:
		static void normalizeAngle(TransformProperty& _prop);

		static TransformProperty::Rotate normalizedAngle(const TransformProperty::Rotate& _rotate);

		static bool isFlexDirectionRowType(const FlexProperty& _flex);

		static bool isFlexDirectionColumnType(const FlexProperty& _flex);

		static bool isFlexDirectionReverseType(const FlexProperty& _flex);

		static bool isPositionAbsolute(const PositionProperty& _position);

		static bool isPositionRelative(const PositionProperty& _position);

		static float clampFloat(float _value, float _min, float _max);

		static unsigned int clampUnsignedInt(unsigned int _value, unsigned int _min, unsigned int _max);

		static float calculateJustifyContentOffset(const AlignProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize);

		static float calculateAlignItemsOffset(const AlignProperty& _alignItems, float _elementSize, float _parentSize);

		static void applyWorldTransform(sf::Transformable& _transformable, const sf::Transform& _transform);
	};
}