#pragma once

#include "Property.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

namespace sfui
{
	class SFUIL_API ImageProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class Repeat : char
		{
			NoRepeat,
			Repeat
		};

		[[nodiscard]] Repeat getRepeat() const;
		void setRepeat(Repeat _repeat);
		void resetRepeat();

		enum class Smooth : char
		{
			Pixelated,
			Smooth
		};

		[[nodiscard]] Smooth getSmooth() const;
		void setSmooth(Smooth _smooth);
		void resetSmooth();

		[[nodiscard]] const char* getImagePath() const;
		void setImagePath(const char* _imagePath);
		void resetImagePath();

		[[nodiscard]] const sf::Color& getTintColor() const;
		void setTintColor(const sf::Color& _color);
		void setTintColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a = 255);
		void resetTintColor();

		[[nodiscard]] const sf::Image& getImage() const;
		bool loadImage();

		enum class SizeType : char
		{
			Pixels,
			Percentage
		};

		struct SizeValue
		{
			float value = 100.f;
			SizeType type = SizeType::Percentage;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Size
		{
			SizeValue width;
			bool widthDirty = false;
			SizeValue height;
			bool heightDirty = false;
		};

		[[nodiscard]] const Size& getSize() const;
		void setSize(const Size& _size);
		void setWidth(float _value, SizeType _type);
		void setWidth(float _value);
		void setHeight(float _value, SizeType _type);
		void setHeight(float _value);
		void resetSize();
		void resetWidth();
		void resetHeight();

		enum class PositionXPositionType : char
		{
			Left,
			Center,
			Right
		};

		enum class PositionYPositionType : char
		{
			Top,
			Center,
			Bottom
		};

		enum class PositionOffsetType : char
		{
			Pixels,
			Percentage
		};

		struct PositionX
		{
			PositionXPositionType position = PositionXPositionType::Center;
			float offsetValue = 0.f;
			PositionOffsetType offsetType = PositionOffsetType::Pixels;

			float resolveToPixels(float _relativeSize, float _relativeTo) const;
		};

		struct PositionY
		{
			PositionYPositionType position = PositionYPositionType::Center;
			float offsetValue = 0.f;
			PositionOffsetType offsetType = PositionOffsetType::Pixels;

			float resolveToPixels(float _relativeSize, float _relativeTo) const;
		};

		[[nodiscard]] const PositionX& getPositionX() const;
		void setPositionX(const PositionX& _positionX);
		void setPositionX(PositionXPositionType _position, float _offsetValue, PositionOffsetType _offsetType);
		void setPositionX(PositionXPositionType _position, float _offsetValue);
		void setPositionX(float _offsetValue, PositionOffsetType _offsetType);
		void setPositionX(float _offsetValue);
		void setPositionX(PositionXPositionType _position);
		void resetPositionX();

		[[nodiscard]] const PositionY& getPositionY() const;
		void setPositionY(const PositionY& _positionY);
		void setPositionY(PositionYPositionType _position, float _offsetValue, PositionOffsetType _offsetType);
		void setPositionY(PositionYPositionType _position, float _offsetValue);
		void setPositionY(float _offsetValue, PositionOffsetType _offsetType);
		void setPositionY(float _offsetValue);
		void setPositionY(PositionYPositionType _position);
		void resetPositionY();

		enum class ScaleMode : char
		{
			StretchToFill,
			ScaleAndCrop,
			ScaleToFit
		};

		[[nodiscard]] ScaleMode getScaleMode() const;
		void setScaleMode(ScaleMode _mode);
		void resetScaleMode();

	private:
		const char* m_imagePath = nullptr;
		bool m_imagePathDirty = false;
		sf::Image m_image;
		sf::Color m_tintColor = sf::Color::White;
		bool m_tintColorDirty = false;
		Repeat m_repeat = Repeat::NoRepeat;
		bool m_repeatDirty = false;
		Smooth m_smooth = Smooth::Pixelated;
		bool m_smoothDirty = false;
		Size m_size;
		PositionX m_positionX;
		bool m_positionXDirty = false;
		PositionY m_positionY;
		bool m_positionYDirty = false;
		ScaleMode m_scaleMode = ScaleMode::StretchToFill;
		bool m_scaleModeDirty = false;
	};
}