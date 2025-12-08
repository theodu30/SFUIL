#include "../../Headers/SFUIL/System/Properties/ImageProperty.hpp"

namespace sfui
{
	void ImageProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_repeatDirty)
		{
			switch (m_repeat)
			{
			case Repeat::NoRepeat: _stream << "image-repeat: no-repeat; "; break;
			case Repeat::Repeat: _stream << "image-repeat: repeat; "; break;
			default: break;
			}
		}

		if (m_smoothDirty)
		{
			switch (m_smooth)
			{
			case Smooth::Pixelated: _stream << "image-smooth: pixelated; "; break;
			case Smooth::Smooth: _stream << "image-smooth: smooth; "; break;
			default: break;
			}
		}

		if (m_imagePathDirty)
		{
			_stream << "image-path: \'" << m_imagePath << "\'; ";
		}

		if (m_tintColorDirty)
		{
			_stream << "image-tint: ("
				<< static_cast<int>(m_tintColor.r) << ","
				<< static_cast<int>(m_tintColor.g) << ","
				<< static_cast<int>(m_tintColor.b) << ","
				<< static_cast<int>(m_tintColor.a) << "); ";
		}

		if (m_size.widthDirty)
		{
			switch (m_size.width.type)
			{
			case SizeType::Pixels: _stream << "image-width: " << m_size.width.value << "px; "; break;
			case SizeType::Percentage: _stream << "image-width: " << m_size.width.value << "%;"; break;
			default: break;
			}
		}

		if (m_size.heightDirty)
		{
			switch (m_size.height.type)
			{
			case SizeType::Pixels: _stream << "image-height: " << m_size.height.value << "px; "; break;
			case SizeType::Percentage: _stream << "image-height: " << m_size.height.value << "%; "; break;
			default: break;
			}
		}

		if (m_positionXDirty)
		{
			switch (m_positionX.position)
			{
			case PositionXPositionType::Left: _stream << "image-position-x: left; "; break;
			case PositionXPositionType::Center: _stream << "image-position-x: center; "; break;
			case PositionXPositionType::Right: _stream << "image-position-x: right; "; break;
			default: break;
			}
			if (m_positionX.position != PositionXPositionType::Center)
			{
				switch (m_positionX.offsetType)
				{
				case PositionOffsetType::Pixels: _stream << "image-position-x-offset:" << m_positionX.offsetValue << "px; "; break;
				case PositionOffsetType::Percentage: _stream << "image-position-x-offset:" << m_positionX.offsetValue << "%; "; break;
				default: break;
				}
			}
		}

		if (m_positionYDirty)
		{
			switch (m_positionY.position)
			{
			case PositionYPositionType::Top: _stream << "image-position-y: top; "; break;
			case PositionYPositionType::Center: _stream << "image-position-y: center; "; break;
			case PositionYPositionType::Bottom: _stream << "image-position-y: bottom; "; break;
			default: break;
			}
			if (m_positionY.position != PositionYPositionType::Center)
			{
				switch (m_positionY.offsetType)
				{
				case PositionOffsetType::Pixels: _stream << "image-position-y-offset:" << m_positionY.offsetValue << "px; "; break;
				case PositionOffsetType::Percentage: _stream << "image-position-y-offset:" << m_positionY.offsetValue << "%; "; break;
				default: break;
				}
			}
		}

		if (m_scaleModeDirty)
		{
			switch (m_scaleMode)
			{
			case ScaleMode::StretchToFill: _stream << "image-scale-mode: stretch-to-fill; "; break;
			case ScaleMode::ScaleAndCrop: _stream << "image-scale-mode: scale-and-crop; "; break;
			case ScaleMode::ScaleToFit: _stream << "image-scale-mode: scale-to-fit; "; break;
			default: break;
			}
		}
	}

	ImageProperty::Repeat ImageProperty::getRepeat() const
	{
		return m_repeat;
	}

	void ImageProperty::setRepeat(Repeat _repeat)
	{
		m_repeat = _repeat;
		m_repeatDirty = true;
	}

	void ImageProperty::resetRepeat()
	{
		m_repeat = Repeat::NoRepeat;
		m_repeatDirty = false;
	}

	ImageProperty::Smooth ImageProperty::getSmooth() const
	{
		return m_smooth;
	}

	void ImageProperty::setSmooth(Smooth _smooth)
	{
		m_smooth = _smooth;
		m_smoothDirty = true;
	}

	void ImageProperty::resetSmooth()
	{
		m_smooth = Smooth::Pixelated;

	}

	const char* ImageProperty::getImagePath() const
	{
		return m_imagePath;
	}

	void ImageProperty::setImagePath(const char* _imagePath)
	{
		m_imagePath = _imagePath;
		m_imagePathDirty = true;
	}

	void ImageProperty::resetImagePath()
	{
		m_imagePath = nullptr;
		m_imagePathDirty = false;
	}

	const sf::Color& ImageProperty::getTintColor() const
	{
		return m_tintColor;
	}

	void ImageProperty::setTintColor(const sf::Color& _color)
	{
		m_tintColor = _color;
		m_tintColorDirty = true;
	}

	void ImageProperty::setTintColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_tintColor.r = _r;
		m_tintColor.g = _g;
		m_tintColor.b = _b;
		m_tintColor.a = _a;
		m_tintColorDirty = true;
	}

	void ImageProperty::resetTintColor()
	{
		m_tintColor = sf::Color::White;
		m_tintColorDirty = false;
	}

	const sf::Image& ImageProperty::getImage() const
	{
		return m_image;
	}

	bool ImageProperty::loadImage()
	{
		if (m_imagePath != nullptr)
		{
			return m_image.loadFromFile(m_imagePath);
		}
		return false;
	}

	float ImageProperty::SizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case SizeType::Pixels:
			return value;
		case SizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const ImageProperty::Size& ImageProperty::getSize() const
	{
		return m_size;
	}

	void ImageProperty::setSize(const Size& _size)
	{
		m_size = _size;
		m_size.widthDirty = true;
		m_size.heightDirty = true;
	}

	void ImageProperty::setWidth(float _value, SizeType _type)
	{
		m_size.width.value = _value;
		m_size.width.type = _type;
		m_size.widthDirty = true;
	}

	void ImageProperty::setWidth(float _value)
	{
		m_size.width.value = _value;
		m_size.widthDirty = true;
	}

	void ImageProperty::setHeight(float _value, SizeType _type)
	{
		m_size.height.value = _value;
		m_size.height.type = _type;
		m_size.heightDirty = true;
	}

	void ImageProperty::setHeight(float _value)
	{
		m_size.height.value = _value;
		m_size.heightDirty = true;
	}

	void ImageProperty::resetSize()
	{
		m_size = Size();
		m_size.widthDirty = false;
		m_size.heightDirty = false;
	}

	void ImageProperty::resetWidth()
	{
		m_size.width = SizeValue();
		m_size.widthDirty = false;
	}

	void ImageProperty::resetHeight()
	{
		m_size.height = SizeValue();
		m_size.heightDirty = false;
	}

	float ImageProperty::PositionX::resolveToPixels(float _relativeSize, float _relativeTo) const
	{
		if (position == PositionXPositionType::Center)
		{
			return (_relativeTo / 2.f) - (_relativeSize / 2.f);
		}
		else if (position == PositionXPositionType::Right)
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return _relativeTo - _relativeSize - offsetValue;
			case PositionOffsetType::Percentage:
				return _relativeTo - _relativeSize - ((offsetValue / 100.f) * _relativeTo);
			default:
				return 0.f;
			}
		}
		else // Left
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return offsetValue;
			case PositionOffsetType::Percentage:
				return (offsetValue / 100.f) * _relativeTo;
			default:
				return 0.f;
			}
		}
	}

	float ImageProperty::PositionY::resolveToPixels(float _relativeSize, float _relativeTo) const
	{
		if (position == PositionYPositionType::Center)
		{
			return (_relativeTo / 2.f) - (_relativeSize / 2.f);
		}
		else if (position == PositionYPositionType::Bottom)
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return _relativeTo - _relativeSize - offsetValue;
			case PositionOffsetType::Percentage:
				return _relativeTo - _relativeSize - ((offsetValue / 100.f) * _relativeTo);
			default:
				return 0.f;
			}
		}
		else // Top
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return offsetValue;
			case PositionOffsetType::Percentage:
				return (offsetValue / 100.f) * _relativeTo;
			default:
				return 0.f;
			}
		}
	}

	const ImageProperty::PositionX& ImageProperty::getPositionX() const
	{
		return m_positionX;
	}

	void ImageProperty::setPositionX(const PositionX& _positionX)
	{
		m_positionX = _positionX;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(PositionXPositionType _position, float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionX.position = _position;
		m_positionX.offsetValue = _offsetValue;
		m_positionX.offsetType = _offsetType;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(PositionXPositionType _position, float _offsetValue)
	{
		m_positionX.position = _position;
		m_positionX.offsetValue = _offsetValue;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionX.offsetValue = _offsetValue;
		m_positionX.offsetType = _offsetType;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(float _offsetValue)
	{
		m_positionX.offsetValue = _offsetValue;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(PositionXPositionType _position)
	{
		m_positionX.position = _position;
		m_positionXDirty = true;
	}

	void ImageProperty::resetPositionX()
	{
		m_positionX = PositionX();
		m_positionXDirty = false;
	}

	const ImageProperty::PositionY& ImageProperty::getPositionY() const
	{
		return m_positionY;
	}

	void ImageProperty::setPositionY(const PositionY& _positionY)
	{
		m_positionY = _positionY;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(PositionYPositionType _position, float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionY.position = _position;
		m_positionY.offsetValue = _offsetValue;
		m_positionY.offsetType = _offsetType;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(PositionYPositionType _position, float _offsetValue)
	{
		m_positionY.position = _position;
		m_positionY.offsetValue = _offsetValue;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionY.offsetValue = _offsetValue;
		m_positionY.offsetType = _offsetType;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(float _offsetValue)
	{
		m_positionY.offsetValue = _offsetValue;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(PositionYPositionType _position)
	{
		m_positionY.position = _position;
		m_positionYDirty = true;
	}

	void ImageProperty::resetPositionY()
	{
		m_positionY = PositionY();
		m_positionYDirty = false;
	}

	ImageProperty::ScaleMode ImageProperty::getScaleMode() const
	{
		return m_scaleMode;
	}

	void ImageProperty::setScaleMode(ScaleMode _mode)
	{
		m_scaleMode = _mode;
		m_scaleModeDirty = true;
	}

	void ImageProperty::resetScaleMode()
	{
		m_scaleMode = ScaleMode::StretchToFill;
		m_scaleModeDirty = false;
	}
}
