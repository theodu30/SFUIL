#include "../../Headers/SFUIL/System/Properties/SizeProperty.hpp"
#include <string>

namespace sfui
{
	float SizeProperty::SizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case SizeType::Auto:
			return 0.f;
		case SizeType::Pixels:
			return value;
		case SizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	void SizeProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_size.widthDirty)
		{
			switch (m_size.width.type)
			{
			case SizeType::Auto: _stream << "width: auto; "; break;
			case SizeType::Pixels: _stream << "width: " << m_size.width.value << "px; "; break;
			case SizeType::Percentage: _stream << "width: " << m_size.width.value << "%; "; break;
			default: break;
			}
		}

		if (m_size.heightDirty)
		{
			switch (m_size.height.type)
			{
			case SizeType::Auto: _stream << "height: auto; "; break;
			case SizeType::Pixels: _stream << "height: " << m_size.height.value << "px; "; break;
			case SizeType::Percentage: _stream << "height: " << m_size.height.value << "%; "; break;
			default: break;
			}
		}

		if (m_minSize.widthDirty)
		{
			switch (m_minSize.width.type)
			{
			case MinSizeType::Auto: _stream << "min-width: auto; "; break;
			case MinSizeType::Pixels: _stream << "min-width: " << m_minSize.width.value << "px; "; break;
			case MinSizeType::Percentage: _stream << "min-width: " << m_minSize.width.value << "%; "; break;
			default: break;
			}
		}

		if (m_minSize.heightDirty)
		{
			switch (m_minSize.height.type)
			{
			case MinSizeType::Auto: _stream << "min-height: auto; "; break;
			case MinSizeType::Pixels: _stream << "min-height: " << m_minSize.height.value << "px; "; break;
			case MinSizeType::Percentage: _stream << "min-height: " << m_minSize.height.value << "%; "; break;
			default: break;
			}
		}

		if (m_maxSize.widthDirty)
		{
			switch (m_maxSize.width.type)
			{
			case MaxSizeType::None: _stream << "max-width: auto; "; break;
			case MaxSizeType::Pixels: _stream << "max-width: " << m_maxSize.width.value << "px; "; break;
			case MaxSizeType::Percentage: _stream << "max-width: " << m_maxSize.width.value << "%; "; break;
			default: break;
			}
		}

		if (m_maxSize.heightDirty)
		{
			switch (m_maxSize.height.type)
			{
			case MaxSizeType::None: _stream << "max-height: auto; "; break;
			case MaxSizeType::Pixels: _stream << "max-height: " << m_maxSize.height.value << "px; "; break;
			case MaxSizeType::Percentage: _stream << "max-height: " << m_maxSize.height.value << "%;  "; break;
			default: break;
			}
		}
	}

	const SizeProperty::Size& SizeProperty::getSize() const
	{
		return m_size;
	}

	void SizeProperty::setSize(const Size& _size)
	{
		m_size = _size;
		m_size.widthDirty = true;
		m_size.heightDirty = true;
	}

	void SizeProperty::setWidth(float _value, SizeType _type)
	{
		m_size.width.value = _value;
		m_size.width.type = _type;
		m_size.widthDirty = true;
	}

	void SizeProperty::setWidth(float _value)
	{
		m_size.width.value = _value;
		m_size.widthDirty = true;
	}

	void SizeProperty::setHeight(float _value, SizeType _type)
	{
		m_size.height.value = _value;
		m_size.height.type = _type;
		m_size.heightDirty = true;
	}

	void SizeProperty::setHeight(float _value)
	{
		m_size.height.value = _value;
		m_size.heightDirty = true;
	}

	void SizeProperty::resetSize()
	{
		m_size = Size();
		m_size.widthDirty = false;
		m_size.heightDirty = false;
	}

	void SizeProperty::resetWidth()
	{
		m_size.width = SizeValue();
		m_size.widthDirty = false;
	}

	void SizeProperty::resetHeight()
	{
		m_size.height = SizeValue();
		m_size.heightDirty = false;
	}

	void SizeProperty::setWidthFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetWidth();
			return;
		}

		if (std::string(_value) == "auto")
		{
			setWidth(0.f, SizeType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setWidth(val, SizeType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setWidth(val, SizeType::Percentage);
		}
		else
		{
			resetWidth();
		}
	}

	void SizeProperty::setHeightFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetHeight();
			return;
		}

		if (std::string(_value) == "auto")
		{
			setHeight(0.f, SizeType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setHeight(val, SizeType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setHeight(val, SizeType::Percentage);
		}
		else
		{
			resetHeight();
		}
	}

	float SizeProperty::MinSizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MinSizeType::Auto:
			return 0.f;
		case MinSizeType::Pixels:
			return value;
		case MinSizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SizeProperty::MinSize& SizeProperty::getMinSize() const
	{
		return m_minSize;
	}

	void SizeProperty::setMinSize(const MinSize& _minSize)
	{
		m_minSize = _minSize;
		m_minSize.widthDirty = true;
		m_minSize.heightDirty = true;
	}

	void SizeProperty::setMinWidth(float _value, MinSizeType _type)
	{
		m_minSize.width.value = _value;
		m_minSize.width.type = _type;
		m_minSize.widthDirty = true;
	}

	void SizeProperty::setMinWidth(float _value)
	{
		m_minSize.width.value = _value;
		m_minSize.widthDirty = true;
	}

	void SizeProperty::setMinHeight(float _value, MinSizeType _type)
	{
		m_minSize.height.value = _value;
		m_minSize.height.type = _type;
		m_minSize.heightDirty = true;
	}

	void SizeProperty::setMinHeight(float _value)
	{
		m_minSize.height.value = _value;
		m_minSize.heightDirty = true;
	}

	void SizeProperty::resetMinSize()
	{
		m_minSize = MinSize();
		m_minSize.widthDirty = false;
		m_minSize.heightDirty = false;
	}

	void SizeProperty::resetMinWidth()
	{
		m_minSize.width = MinSizeValue();
		m_minSize.widthDirty = false;
	}

	void SizeProperty::resetMinHeight()
	{
		m_minSize.height = MinSizeValue();
		m_minSize.heightDirty = false;
	}

	void SizeProperty::setMinWidthFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMinWidth();
			return;
		}

		if (std::string(_value) == "auto")
		{
			setMinWidth(0.f, MinSizeType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMinWidth(val, MinSizeType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMinWidth(val, MinSizeType::Percentage);
		}
		else
		{
			resetMinWidth();
		}
	}

	void SizeProperty::setMinHeightFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMinHeight();
			return;
		}

		if (std::string(_value) == "auto")
		{
			setMinHeight(0.f, MinSizeType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMinHeight(val, MinSizeType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMinHeight(val, MinSizeType::Percentage);
		}
		else
		{
			resetMinHeight();
		}
	}

	float SizeProperty::MaxSizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MaxSizeType::None:
			return _relativeTo;
		case MaxSizeType::Pixels:
			return value;
		case MaxSizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return _relativeTo;
		}
	}

	const SizeProperty::MaxSize& SizeProperty::getMaxSize() const
	{
		return m_maxSize;
	}

	void SizeProperty::setMaxSize(const MaxSize& _maxSize)
	{
		m_maxSize = _maxSize;
		m_maxSize.widthDirty = true;
		m_maxSize.heightDirty = true;
	}

	void SizeProperty::setMaxWidth(float _value, MaxSizeType _type)
	{
		m_maxSize.width.value = _value;
		m_maxSize.width.type = _type;
		m_maxSize.widthDirty = true;
	}

	void SizeProperty::setMaxWidth(float _value)
	{
		m_maxSize.width.value = _value;
		m_maxSize.widthDirty = true;
	}

	void SizeProperty::setMaxHeight(float _value, MaxSizeType _type)
	{
		m_maxSize.height.value = _value;
		m_maxSize.height.type = _type;
		m_maxSize.heightDirty = true;
	}

	void SizeProperty::setMaxHeight(float _value)
	{
		m_maxSize.height.value = _value;
		m_maxSize.heightDirty = true;
	}

	void SizeProperty::resetMaxSize()
	{
		m_maxSize = MaxSize();
		m_maxSize.widthDirty = false;
		m_maxSize.heightDirty = false;
	}

	void SizeProperty::resetMaxWidth()
	{
		m_maxSize.width = MaxSizeValue();
		m_maxSize.widthDirty = false;
	}

	void SizeProperty::resetMaxHeight()
	{
		m_maxSize.height = MaxSizeValue();
		m_maxSize.heightDirty = false;
	}

	void SizeProperty::setMaxWidthFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMaxWidth();
			return;
		}

		if (std::string(_value) == "auto")
		{
			setMaxWidth(0.f, MaxSizeType::None);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMaxWidth(val, MaxSizeType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMaxWidth(val, MaxSizeType::Percentage);
		}
		else
		{
			resetMaxWidth();
		}
	}

	void SizeProperty::setMaxHeightFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMaxHeight();
			return;
		}

		if (std::string(_value) == "auto")
		{
			setMaxHeight(0.f, MaxSizeType::None);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMaxHeight(val, MaxSizeType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMaxHeight(val, MaxSizeType::Percentage);
		}
		else
		{
			resetMaxHeight();
		}
	}

}
