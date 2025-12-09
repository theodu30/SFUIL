#include "../../Headers/SFUIL/System/Properties/TransformProperty.hpp"
#include "../../Headers/SFUIL/UIElement.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

namespace sfui
{
	float TransformProperty::OriginValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case OriginType::Pixels:
			return value;
		case OriginType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	void TransformProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_origin.xDirty)
		{
			switch (m_origin.x.type)
			{
			case OriginType::Pixels: _stream << "origin-x: " << m_origin.x.value << "px; "; break;
			case OriginType::Percentage: _stream << "origin-x: " << m_origin.x.value << "%; "; break;
			default: break;
			}
		}

		if (m_origin.yDirty)
		{
			switch (m_origin.y.type)
			{
			case OriginType::Pixels: _stream << "origin-y: " << m_origin.y.value << "px; "; break;
			case OriginType::Percentage: _stream << "origin-y: " << m_origin.y.value << "%; "; break;
			default: break;
			}
		}

		if (m_translate.xDirty)
		{
			switch (m_translate.x.type)
			{
			case TranslateType::Pixels: _stream << "translate-x: " << m_translate.x.value << "px; "; break;
			case TranslateType::Percentage: _stream << "translate-x: " << m_translate.x.value << "%; "; break;
			default: break;
			}
		}

		if (m_translate.yDirty)
		{
			switch (m_translate.y.type)
			{
			case TranslateType::Pixels: _stream << "translate-y: " << m_translate.y.value << "px; "; break;
			case TranslateType::Percentage: _stream << "translate-y: " << m_translate.y.value << "%; "; break;
			default: break;
			}
		}

		if (m_scale.xDirty)
		{
			_stream << "scale-x: " << m_scale.x << "; ";
		}

		if (m_scale.yDirty)
		{
			_stream << "scale-y: " << m_scale.y << "; ";
		}

		if (m_rotateDirty)
		{
			switch (m_rotate.type)
			{
			case RotateType::Degrees: _stream << "rotate: " << m_rotate.value << "deg; "; break;
			case RotateType::Radians: _stream << "rotate: " << m_rotate.value << "rad; "; break;
			default: break;
			}
		}
	}

	const TransformProperty::Origin& TransformProperty::getOrigin() const
	{
		return m_origin;
	}

	void TransformProperty::setOrigin(const Origin& _origin)
	{
		m_origin = _origin;
		m_origin.xDirty = true;
		m_origin.yDirty = true;
	}

	void TransformProperty::setOriginX(float _value, OriginType _type)
	{
		m_origin.x.value = _value;
		m_origin.x.type = _type;
		m_origin.xDirty = true;
	}

	void TransformProperty::setOriginX(float _value)
	{
		m_origin.x.value = _value;
		m_origin.xDirty = true;
	}

	void TransformProperty::setOriginY(float _value, OriginType _type)
	{
		m_origin.y.value = _value;
		m_origin.y.type = _type;
		m_origin.yDirty = true;
	}

	void TransformProperty::setOriginY(float _value)
	{
		m_origin.y.value = _value;
		m_origin.yDirty = true;
	}

	void TransformProperty::resetOrigin()
	{
		m_origin = Origin();
		m_origin.xDirty = false;
		m_origin.yDirty = false;
	}

	void TransformProperty::resetOriginX()
	{
		m_origin.x = OriginValue();
		m_origin.xDirty = false;
	}

	void TransformProperty::resetOriginY()
	{
		m_origin.y = OriginValue();
		m_origin.yDirty = false;
	}

	float TransformProperty::TranslateValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case TranslateType::Pixels:
			return value;
		case TranslateType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const TransformProperty::Translate& TransformProperty::getTranslate() const
	{
		return m_translate;
	}

	void TransformProperty::setTranslate(const Translate& _translate)
	{
		m_translate = _translate;
		m_translate.xDirty = true;
		m_translate.yDirty = true;
	}

	void TransformProperty::setTranslateX(float _value, TranslateType _type)
	{
		m_translate.x.value = _value;
		m_translate.x.type = _type;
		m_translate.xDirty = true;
	}

	void TransformProperty::setTranslateX(float _value)
	{
		m_translate.x.value = _value;
		m_translate.xDirty = true;
	}

	void TransformProperty::setTranslateY(float _value, TranslateType _type)
	{
		m_translate.y.value = _value;
		m_translate.y.type = _type;
		m_translate.yDirty = true;
	}

	void TransformProperty::setTranslateY(float _value)
	{
		m_translate.y.value = _value;
		m_translate.yDirty = true;
	}

	void TransformProperty::resetTranslate()
	{
		m_translate = Translate();
		m_translate.xDirty = false;
		m_translate.yDirty = false;
	}

	void TransformProperty::resetTranslateX()
	{
		m_translate.x = TranslateValue();
		m_translate.xDirty = false;
	}

	void TransformProperty::resetTranslateY()
	{
		m_translate.y = TranslateValue();
		m_translate.yDirty = false;
	}

	const TransformProperty::Scale& TransformProperty::getScale() const
	{
		return m_scale;
	}

	void TransformProperty::setScale(const Scale& _scale)
	{
		m_scale = _scale;
		m_scale.xDirty = true;
		m_scale.yDirty = true;
	}

	void TransformProperty::setScaleX(float _value)
	{
		m_scale.x = _value;
		m_scale.xDirty = true;
	}

	void TransformProperty::setScaleY(float _value)
	{
		m_scale.y = _value;
		m_scale.yDirty = true;
	}

	void TransformProperty::resetScale()
	{
		m_scale = Scale();
		m_scale.xDirty = false;
		m_scale.yDirty = false;
	}

	void TransformProperty::resetScaleX()
	{
		m_scale.x = 1.f;
	}

	void TransformProperty::resetScaleY()
	{
		m_scale.y = 1.f;
	}

	float TransformProperty::Rotate::resolveToDegrees() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return value;
		case RotateType::Radians:
			return value * (180.f / static_cast<float>(M_PI));
		default:
			return 0.f;
		}
	}

	float TransformProperty::Rotate::resolveToRadians() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return value * (static_cast<float>(M_PI) / 180.f);
		case RotateType::Radians:
			return value;
		default:
			return 0.f;
		}
	}

	sf::Angle TransformProperty::Rotate::resolveToSfAngle() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return sf::degrees(value);
		case RotateType::Radians:
			return sf::radians(value);
		default:
			return sf::degrees(0.f);
		}
	}

	const TransformProperty::Rotate& TransformProperty::getRotate() const
	{
		return m_rotate;
	}

	void TransformProperty::setRotate(const Rotate& _rotate)
	{
		m_rotate = _rotate;
		m_rotateDirty = true;
	}

	void TransformProperty::setRotate(float _value, RotateType _type)
	{
		m_rotate.value = _value;
		m_rotate.type = _type;
		m_rotateDirty = true;
	}

	void TransformProperty::setRotate(float _value)
	{
		m_rotate.value = _value;
		m_rotateDirty = true;
	}

	void TransformProperty::resetRotate()
	{
		m_rotate = Rotate();
		m_rotateDirty = false;
	}

	const sf::Vector2f& TransformProperty::getCalculatedOriginPixels() const
	{
		return m_calculatedOriginPixels;
	}

	void TransformProperty::setCalculatedOriginPixels(const sf::Vector2f& _pixels)
	{
		m_calculatedOriginPixels = _pixels;
	}

	void TransformProperty::setCalculatedOriginPixels(float _xPixels, float _yPixels)
	{
		m_calculatedOriginPixels.x = _xPixels;
		m_calculatedOriginPixels.y = _yPixels;
	}

	const sf::Vector2f& TransformProperty::getCalculatedTranslatePixels() const
	{
		return m_calculatedTranslatePixels;
	}

	void TransformProperty::setCalculatedTranslatePixels(const sf::Vector2f& _pixels)
	{
		m_calculatedTranslatePixels = _pixels;
	}

	void TransformProperty::setCalculatedTranslatePixels(float _xPixels, float _yPixels)
	{
		m_calculatedTranslatePixels.x = _xPixels;
		m_calculatedTranslatePixels.y = _yPixels;
	}

	const sf::Vector2f& TransformProperty::getCalculatedScale() const
	{
		return m_calculatedScale;
	}

	void TransformProperty::setCalculatedScale(const sf::Vector2f& _scale)
	{
		m_calculatedScale = _scale;
	}

	void TransformProperty::setCalculatedScale(float _xScale, float _yScale)
	{
		m_calculatedScale.x = _xScale;
		m_calculatedScale.y = _yScale;
	}

	const sf::Angle& TransformProperty::getCalculatedRotateAngle() const
	{
		return m_calculatedRotateAngle;
	}

	void TransformProperty::setCalculatedRotateAngle(const sf::Angle& _angle)
	{
		m_calculatedRotateAngle = _angle;
	}

	sf::Transform TransformProperty::getLocalTransform() const
	{
		sf::Transform t;

		t.translate(m_calculatedTranslatePixels);
		t.translate(m_calculatedOriginPixels);
		t.rotate(m_calculatedRotateAngle);
		t.scale(m_calculatedScale);
		t.translate(-m_calculatedOriginPixels);

		return t;
	}

	sf::Transform TransformProperty::getWorldTransform(const UIElement* _element) const
	{
		sf::Transform local = getLocalTransform();

		if (_element->getConstParent())
		{
			local = _element->getConstParent()->getConstProperty<TransformProperty>().getWorldTransform(_element->getConstParent()) * local;
		}

		return local;
	}

	sf::Vector2f TransformProperty::Scale::toVector2f() const
	{
		return sf::Vector2f(x, y);
	}

	sf::Vector2f TransformProperty::Translate::toVector2f(float _relativeToX, float _relativeToY) const
	{
		return sf::Vector2f(
			x.resolveToPixels(_relativeToX),
			y.resolveToPixels(_relativeToY)
		);
	}

	sf::Vector2f TransformProperty::Origin::toVector2f(float _relativeToX, float _relativeToY) const
	{
		return sf::Vector2f(
			x.resolveToPixels(_relativeToX),
			y.resolveToPixels(_relativeToY)
		);
	}
}
