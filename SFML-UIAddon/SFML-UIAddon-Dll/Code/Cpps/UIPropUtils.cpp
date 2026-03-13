#include "../Headers/SFUIL/System/UIPropUtils.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

namespace sfui
{
	bool UIPropUtils::isFlexDirectionRowType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::Row ||
			_flex.getFlexDirection() == FlexProperty::Direction::RowReverse;
	}

	bool UIPropUtils::isFlexDirectionColumnType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::Column ||
			_flex.getFlexDirection() == FlexProperty::Direction::ColumnReverse;
	}

	bool UIPropUtils::isFlexDirectionReverseType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::RowReverse ||
			_flex.getFlexDirection() == FlexProperty::Direction::ColumnReverse;
	}

	bool UIPropUtils::isPositionAbsolute(const PositionProperty& _position)
	{
		return _position.getMode() == PositionProperty::Mode::Absolute;
	}

	bool UIPropUtils::isPositionRelative(const PositionProperty& _position)
	{
		return _position.getMode() == PositionProperty::Mode::Relative;
	}

	float UIPropUtils::clampFloat(float _value, float _min, float _max)
	{
		if (_value < _min)
			return _min;
		if (_value > _max)
			return _max;
		return _value;
	}

	unsigned int UIPropUtils::clampUnsignedInt(unsigned int _value, unsigned int _min, unsigned int _max)
	{
		if (_value < _min)
			return _min;
		if (_value > _max)
			return _max;
		return _value;
	}

	float UIPropUtils::calculateJustifyContentOffset(const AlignProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize)
	{
		switch (_justifyContent.getJustifyContent())
		{
		case AlignProperty::JustifyContent::FlexStart:
			return static_cast<float>(_siblingIndex) * _elementSize;
		case AlignProperty::JustifyContent::FlexEnd:
			return _parentSize - (_elementSize * static_cast<float>(_siblingCount - _siblingIndex));
		case AlignProperty::JustifyContent::Center:
			return ((_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / 2.f) + (static_cast<float>(_siblingIndex) * _elementSize);
		case AlignProperty::JustifyContent::SpaceBetween:
			if (_siblingCount > 1)
			{
				float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount - 1);
				return (static_cast<float>(_siblingIndex) * (_elementSize + space));
			}
			else
			{
				return 0.f;
			}
		case AlignProperty::JustifyContent::SpaceAround:
		{
			float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount);
			return (space / 2.f) + (static_cast<float>(_siblingIndex) * (_elementSize + space));
		}
		case AlignProperty::JustifyContent::SpaceEvenly:
		{
			float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount + 1);
			return space + (static_cast<float>(_siblingIndex) * (_elementSize + space));
		}
		default:
			return 0.f;
		}
	}

	float UIPropUtils::calculateAlignItemsOffset(const AlignProperty& _alignItems, float _elementSize, float _parentSize)
	{
		switch (_alignItems.getAlignItems())
		{
		case AlignProperty::AlignItems::FlexStart:
			return 0.f;
		case AlignProperty::AlignItems::FlexEnd:
			return _parentSize - _elementSize;
		case AlignProperty::AlignItems::Center:
			return (_parentSize - _elementSize) / 2.f;
		case AlignProperty::AlignItems::Stretch:
			return 0.f;
		default:
			return 0.f;
		}
	}

	void UIPropUtils::applyWorldTransform(sf::Transformable& _transformable, const sf::Transform& _transform)
	{
		_transformable.setPosition(_transform.transformPoint({ 0.f, 0.f }));

		const float* m = _transform.getMatrix();
		float angleRad = std::atan2(m[1], m[0]);
		_transformable.setRotation(sf::radians(angleRad));

		float scaleX = std::sqrt(m[0] * m[0] + m[1] * m[1]);
		float scaleY = std::sqrt(m[4] * m[4] + m[5] * m[5]);
		_transformable.setScale({ scaleX, scaleY });

		float originX = -m[2] / scaleX;
		float originY = -m[5] / scaleY;
		_transformable.setOrigin({ originX, originY });
	}

	void UIPropUtils::normalizeAngle(TransformProperty& _prop)
	{
		_prop.setRotate(normalizedAngle(_prop.getRotate()));
	}

	TransformProperty::Rotate UIPropUtils::normalizedAngle(const TransformProperty::Rotate& _rotate)
	{
		switch (_rotate.type)
		{
		case TransformProperty::RotateType::Degrees:
		{
			float degrees = std::fmod(_rotate.value, 360.f);
			if (degrees > 180.f)
				degrees -= 360.f;
			else if (degrees < -180.f)
				degrees += 360.f;
			return TransformProperty::Rotate{ degrees, TransformProperty::RotateType::Degrees };
		}
		case TransformProperty::RotateType::Radians:
		{
			const float twoPi = static_cast<float>(2 * M_PI);
			float radians = std::fmod(_rotate.value, twoPi);
			if (radians > static_cast<float>(M_PI))
				radians -= twoPi;
			else if (radians < -static_cast<float>(M_PI))
				radians += twoPi;
			return TransformProperty::Rotate{ radians, TransformProperty::RotateType::Radians };
		}
		default:
			return _rotate;
		}
	}
}