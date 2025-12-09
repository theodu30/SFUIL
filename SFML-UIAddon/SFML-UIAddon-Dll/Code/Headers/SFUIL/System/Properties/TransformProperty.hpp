#pragma once 

#include "Property.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transform.hpp>

namespace sfui
{
	class SFUIL_API TransformProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class OriginType : char
		{
			Pixels,
			Percentage
		};

		struct OriginValue
		{
			float value = 0.f;
			OriginType type = OriginType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Origin
		{
			OriginValue x;
			bool xDirty = false;
			OriginValue y;
			bool yDirty = false;

			sf::Vector2f toVector2f(float _relativeToX, float _relativeToY) const;
		};

		[[nodiscard]] const Origin& getOrigin() const;
		void setOrigin(const Origin& _origin);
		void setOriginX(float _value, OriginType _type);
		void setOriginX(float _value);
		void setOriginY(float _value, OriginType _type);
		void setOriginY(float _value);
		void resetOrigin();
		void resetOriginX();
		void resetOriginY();
		void setOriginXFromCStr(const char* _value);
		void setOriginYFromCStr(const char* _value);

		enum class TranslateType : char
		{
			Pixels,
			Percentage
		};

		struct TranslateValue
		{
			float value = 0.f;
			TranslateType type = TranslateType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Translate
		{
			TranslateValue x;
			bool xDirty = false;
			TranslateValue y;
			bool yDirty = false;

			sf::Vector2f toVector2f(float _relativeToX, float _relativeToY) const;
		};

		[[nodiscard]] const Translate& getTranslate() const;
		void setTranslate(const Translate& _translate);
		void setTranslateX(float _value, TranslateType _type);
		void setTranslateX(float _value);
		void setTranslateY(float _value, TranslateType _type);
		void setTranslateY(float _value);
		void resetTranslate();
		void resetTranslateX();
		void resetTranslateY();
		void setTranslateXFromCStr(const char* _value);
		void setTranslateYFromCStr(const char* _value);

		struct Scale
		{
			float x = 1.f;
			bool xDirty = false;
			float y = 1.f;
			bool yDirty = false;

			sf::Vector2f toVector2f() const;
		};

		[[nodiscard]] const Scale& getScale() const;;
		void setScale(const Scale& _scale);
		void setScaleX(float _value);
		void setScaleY(float _value);
		void resetScale();
		void resetScaleX();
		void resetScaleY();
		void setScaleXFromCStr(const char* _value);
		void setScaleYFromCStr(const char* _value);

		enum class RotateType : char
		{
			Degrees,
			Radians
		};

		struct Rotate
		{
			float value = 0.f;
			RotateType type = RotateType::Degrees;

			float resolveToDegrees() const;
			float resolveToRadians() const;
			sf::Angle resolveToSfAngle() const;
		};

		[[nodiscard]] const Rotate& getRotate() const;
		void setRotate(const Rotate& _rotate);
		void setRotate(float _value, RotateType _type);
		void setRotate(float _value);
		void resetRotate();
		void setRotateFromCStr(const char* _value);

	private:
		Origin m_origin;
		Translate m_translate;
		Scale m_scale;
		Rotate m_rotate;
		bool m_rotateDirty = false;

	public:
		const sf::Vector2f& getCalculatedOriginPixels() const;
		void setCalculatedOriginPixels(const sf::Vector2f& _pixels);
		void setCalculatedOriginPixels(float _xPixels, float _yPixels);
		const sf::Vector2f& getCalculatedTranslatePixels() const;
		void setCalculatedTranslatePixels(const sf::Vector2f& _pixels);
		void setCalculatedTranslatePixels(float _xPixels, float _yPixels);
		const sf::Vector2f& getCalculatedScale() const;
		void setCalculatedScale(const sf::Vector2f& _scale);
		void setCalculatedScale(float _xScale, float _yScale);
		const sf::Angle& getCalculatedRotateAngle() const;
		void setCalculatedRotateAngle(const sf::Angle& _angle);

		sf::Transform getLocalTransform() const;
		sf::Transform getWorldTransform(const UIElement* _element) const;

	private:
		sf::Vector2f m_calculatedOriginPixels;
		sf::Vector2f m_calculatedTranslatePixels;
		sf::Vector2f m_calculatedScale;
		sf::Angle m_calculatedRotateAngle;
	};
}