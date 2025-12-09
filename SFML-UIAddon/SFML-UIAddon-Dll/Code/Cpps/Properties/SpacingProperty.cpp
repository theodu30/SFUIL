#include "../../Headers/SFUIL/System/Properties/SpacingProperty.hpp"
#include <string>

namespace sfui
{
	float SpacingProperty::MarginValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MarginType::Auto:
			return 0.f;
		case MarginType::Pixels:
			return value;
		case MarginType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	void SpacingProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_marginTopDirty)
		{
			switch (m_marginTop.type)
			{
			case MarginType::Auto: _stream << "margin-top: auto; "; break;
			case MarginType::Pixels: _stream << "margin-top:" << m_marginTop.value << "px; "; break;
			case MarginType::Percentage: _stream << "margin-top:" << m_marginTop.value << "%; "; break;
			default: break;
			}
		}

		if (m_marginRightDirty)
		{
			switch (m_marginRight.type)
			{
			case MarginType::Auto: _stream << "margin-right: auto; "; break;
			case MarginType::Pixels: _stream << "margin-right:" << m_marginRight.value << "px; "; break;
			case MarginType::Percentage: _stream << "margin-right:" << m_marginRight.value << "%; "; break;
			default: break;
			}
		}

		if (m_marginBottomDirty)
		{
			switch (m_marginBottom.type)
			{
			case MarginType::Auto: _stream << "margin-bottom: auto; "; break;
			case MarginType::Pixels: _stream << "margin-bottom:" << m_marginBottom.value << "px; "; break;
			case MarginType::Percentage: _stream << "margin-bottom:" << m_marginBottom.value << "%; "; break;
			default: break;
			}
		}

		if (m_marginLeftDirty)
		{
			switch (m_marginLeft.type)
			{
			case MarginType::Auto: _stream << "margin-left: auto; "; break;
			case MarginType::Pixels: _stream << "margin-left:" << m_marginLeft.value << "px; "; break;
			case MarginType::Percentage: _stream << "margin-left:" << m_marginLeft.value << "%; "; break;
			default: break;
			}
		}

		if (m_paddingTopDirty)
		{
			switch (m_paddingTop.type)
			{
			case PaddingType::Auto: _stream << "padding-top: auto; "; break;
			case PaddingType::Pixels: _stream << "padding-top:" << m_paddingTop.value << "px; "; break;
			case PaddingType::Percentage: _stream << "padding-top:" << m_paddingTop.value << "%; "; break;
			default: break;
			}
		}

		if (m_paddingRightDirty)
		{
			switch (m_paddingRight.type)
			{
			case PaddingType::Auto: _stream << "padding-right: auto; "; break;
			case PaddingType::Pixels: _stream << "padding-right:" << m_paddingRight.value << "px; "; break;
			case PaddingType::Percentage: _stream << "padding-right:" << m_paddingRight.value << "%; "; break;
			default: break;
			}
		}

		if (m_paddingBottomDirty)
		{
			switch (m_paddingBottom.type)
			{
			case PaddingType::Auto: _stream << "padding-bottom: auto; "; break;
			case PaddingType::Pixels: _stream << "padding-bottom:" << m_paddingBottom.value << "px; "; break;
			case PaddingType::Percentage: _stream << "padding-bottom:" << m_paddingBottom.value << "%; "; break;
			default: break;
			}
		}

		if (m_paddingLeftDirty)
		{
			switch (m_paddingLeft.type)
			{
			case PaddingType::Auto: _stream << "padding-left: auto; "; break;
			case PaddingType::Pixels: _stream << "padding-left:" << m_paddingLeft.value << "px; "; break;
			case PaddingType::Percentage: _stream << "padding-left:" << m_paddingLeft.value << "%; "; break;
			default: break;
			}
		}
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginTop() const
	{
		return m_marginTop;
	}

	void SpacingProperty::setMarginTop(const MarginValue& _value)
	{
		m_marginTop = _value;
		m_marginTopDirty = true;
	}

	void SpacingProperty::setMarginTop(float _value, MarginType _type)
	{
		m_marginTop.value = _value;
		m_marginTop.type = _type;
		m_marginTopDirty = true;
	}

	void SpacingProperty::setMarginTop(float _value)
	{
		m_marginTop.value = _value;
		m_marginTopDirty = true;
	}

	void SpacingProperty::resetMarginTop()
	{
		m_marginTop = MarginValue();
		m_marginTopDirty = false;
	}

	void SpacingProperty::setMarginTopFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMarginTop();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setMarginTop(0.f, MarginType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMarginTop(val, MarginType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMarginTop(val, MarginType::Percentage);
		}
		else
		{
			resetMarginTop();
		}
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginRight() const
	{
		return m_marginRight;
	}

	void SpacingProperty::setMarginRight(const MarginValue& _value)
	{
		m_marginRight = _value;
		m_marginRightDirty = true;
	}

	void SpacingProperty::setMarginRight(float _value, MarginType _type)
	{
		m_marginRight.value = _value;
		m_marginRight.type = _type;
		m_marginRightDirty = true;
	}

	void SpacingProperty::setMarginRight(float _value)
	{
		m_marginRight.value = _value;
		m_marginRightDirty = true;
	}

	void SpacingProperty::resetMarginRight()
	{
		m_marginRight = MarginValue();
		m_marginRightDirty = false;
	}

	void SpacingProperty::setMarginRightFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMarginRight();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setMarginRight(0.f, MarginType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMarginRight(val, MarginType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMarginRight(val, MarginType::Percentage);
		}
		else
		{
			resetMarginRight();
		}
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginBottom() const
	{
		return m_marginBottom;
	}

	void SpacingProperty::setMarginBottom(const MarginValue& _value)
	{
		m_marginBottom = _value;
		m_marginBottomDirty = true;
	}

	void SpacingProperty::setMarginBottom(float _value, MarginType _type)
	{
		m_marginBottom.value = _value;
		m_marginBottom.type = _type;
		m_marginBottomDirty = true;
	}

	void SpacingProperty::setMarginBottom(float _value)
	{
		m_marginBottom.value = _value;
		m_marginBottomDirty = true;
	}

	void SpacingProperty::resetMarginBottom()
	{
		m_marginBottom = MarginValue();
		m_marginBottomDirty = false;
	}

	void SpacingProperty::setMarginBottomFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMarginBottom();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setMarginBottom(0.f, MarginType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMarginBottom(val, MarginType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMarginBottom(val, MarginType::Percentage);
		}
		else
		{
			resetMarginBottom();
		}
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginLeft() const
	{
		return m_marginLeft;
	}

	void SpacingProperty::setMarginLeft(const MarginValue& _value)
	{
		m_marginLeft = _value;
		m_marginLeftDirty = true;
	}

	void SpacingProperty::setMarginLeft(float _value, MarginType _type)
	{
		m_marginLeft.value = _value;
		m_marginLeft.type = _type;
		m_marginLeftDirty = true;
	}

	void SpacingProperty::setMarginLeft(float _value)
	{
		m_marginLeft.value = _value;
		m_marginLeftDirty = true;
	}

	void SpacingProperty::resetMarginLeft()
	{
		m_marginLeft = MarginValue();
		m_marginLeftDirty = false;
	}

	void SpacingProperty::setMarginLeftFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetMarginLeft();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setMarginLeft(0.f, MarginType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setMarginLeft(val, MarginType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setMarginLeft(val, MarginType::Percentage);
		}
		else
		{
			resetMarginLeft();
		}
	}

	float SpacingProperty::PaddingValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case PaddingType::Auto:
			return 0.f;
		case PaddingType::Pixels:
			return value;
		case PaddingType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingTop() const
	{
		return m_paddingTop;
	}

	void SpacingProperty::setPaddingTop(const PaddingValue& _value)
	{
		m_paddingTop = _value;
		m_paddingTopDirty = false;
	}

	void SpacingProperty::setPaddingTop(float _value, PaddingType _type)
	{
		m_paddingTop.value = _value;
		m_paddingTop.type = _type;
		m_paddingTopDirty = false;
	}

	void SpacingProperty::setPaddingTop(float _value)
	{
		m_paddingTop.value = _value;
		m_paddingTopDirty = false;
	}

	void SpacingProperty::resetPaddingTop()
	{
		m_paddingTop = PaddingValue();
		m_paddingTopDirty = false;
	}

	void SpacingProperty::setPaddingTopFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetPaddingTop();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setPaddingTop(0.f, PaddingType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setPaddingTop(val, PaddingType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setPaddingTop(val, PaddingType::Percentage);
		}
		else
		{
			resetPaddingTop();
		}
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingRight() const
	{
		return m_paddingRight;
	}

	void SpacingProperty::setPaddingRight(const PaddingValue& _value)
	{
		m_paddingRight = _value;
		m_paddingRightDirty = false;
	}

	void SpacingProperty::setPaddingRight(float _value, PaddingType _type)
	{
		m_paddingRight.value = _value;
		m_paddingRight.type = _type;
		m_paddingRightDirty = false;
	}

	void SpacingProperty::setPaddingRight(float _value)
	{
		m_paddingRight.value = _value;
		m_paddingRightDirty = false;
	}

	void SpacingProperty::resetPaddingRight()
	{
		m_paddingRight = PaddingValue();
		m_paddingRightDirty = false;
	}

	void SpacingProperty::setPaddingRightFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetPaddingRight();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setPaddingRight(0.f, PaddingType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setPaddingRight(val, PaddingType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setPaddingRight(val, PaddingType::Percentage);
		}
		else
		{
			resetPaddingRight();
		}
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingBottom() const
	{
		return m_paddingBottom;
	}

	void SpacingProperty::setPaddingBottom(const PaddingValue& _value)
	{
		m_paddingBottom = _value;
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::setPaddingBottom(float _value, PaddingType _type)
	{
		m_paddingBottom.value = _value;
		m_paddingBottom.type = _type;
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::setPaddingBottom(float _value)
	{
		m_paddingBottom.value = _value;
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::resetPaddingBottom()
	{
		m_paddingBottom = PaddingValue();
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::setPaddingBottomFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetPaddingBottom();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setPaddingBottom(0.f, PaddingType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setPaddingBottom(val, PaddingType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setPaddingBottom(val, PaddingType::Percentage);
		}
		else
		{
			resetPaddingBottom();
		}
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingLeft() const
	{
		return m_paddingLeft;
	}

	void SpacingProperty::setPaddingLeft(const PaddingValue& _value)
	{
		m_paddingLeft = _value;
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::setPaddingLeft(float _value, PaddingType _type)
	{
		m_paddingLeft.value = _value;
		m_paddingLeft.type = _type;
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::setPaddingLeft(float _value)
	{
		m_paddingLeft.value = _value;
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::resetPaddingLeft()
	{
		m_paddingLeft = PaddingValue();
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::setPaddingLeftFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetPaddingLeft();
			return;
		}

		if (strcmp(_value, "auto") == 0)
		{
			setPaddingLeft(0.f, PaddingType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setPaddingLeft(val, PaddingType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setPaddingLeft(val, PaddingType::Percentage);
		}
		else
		{
			resetPaddingLeft();
		}
	}

}
