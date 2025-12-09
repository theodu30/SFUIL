#include "../../Headers/SFUIL/System/Properties/PositionProperty.hpp"
#include <string>

namespace sfui
{
	void PositionProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_modeDirty)
		{
			switch (m_mode)
			{
			case Mode::Relative: _stream << "position: relative; "; break;
			case Mode::Absolute: _stream << "position: absolute; "; break;
			default: break;
			}
		}

		if (m_topDirty)
		{
			switch (m_top.type)
			{
			case ValueType::Auto: _stream << "top: auto; "; break;
			case ValueType::Pixels: _stream << "top: " << m_top.value << "px; "; break;
			case ValueType::Percentage: _stream << "top: " << m_top.value << "%; "; break;
			default: break;
			}
		}

		if (m_rightDirty)
		{
			switch (m_right.type)
			{
			case ValueType::Auto: _stream << "right: auto; "; break;
			case ValueType::Pixels: _stream << "right: " << m_right.value << "px; "; break;
			case ValueType::Percentage: _stream << "right: " << m_right.value << "%; "; break;
			default: break;
			}
		}

		if (m_bottomDirty)
		{
			switch (m_bottom.type)
			{
			case ValueType::Auto: _stream << "bottom: auto; "; break;
			case ValueType::Pixels: _stream << "bottom: " << m_bottom.value << "px; "; break;
			case ValueType::Percentage: _stream << "bottom: " << m_bottom.value << "%; "; break;
			default: break;
			}
		}

		if (m_leftDirty)
		{
			switch (m_left.type)
			{
			case ValueType::Auto: _stream << "left: auto; "; break;
			case ValueType::Pixels: _stream << "left: " << m_left.value << "px; "; break;
			case ValueType::Percentage: _stream << "left: " << m_left.value << "%; "; break;
			default: break;
			}
		}
	}

	PositionProperty::Mode PositionProperty::getMode() const
	{
		return m_mode;
	}

	void PositionProperty::setMode(Mode _mode)
	{
		m_mode = _mode;
		m_modeDirty = true;
	}

	void PositionProperty::resetMode()
	{
		m_mode = Mode::Relative;
		m_modeDirty = false;
	}

	void PositionProperty::setModeFromCStr(const char* _modeStr)
	{
		if (_modeStr == nullptr)
		{
			resetMode();
			return;
		}

		if (std::strcmp(_modeStr, "relative") == 0)
		{
			setMode(Mode::Relative);
		}
		else if (std::strcmp(_modeStr, "absolute") == 0)
		{
			setMode(Mode::Absolute);
		}
		else
		{
			resetMode();
		}
	}

	float PositionProperty::Value::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case ValueType::Auto:
			return 0.f;
		case ValueType::Pixels:
			return value;
		case ValueType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const PositionProperty::Value& PositionProperty::getTop() const
	{
		return m_top;
	}

	void PositionProperty::setTop(const Value& _value)
	{
		m_top = _value;
		m_topDirty = true;
	}

	void PositionProperty::setTop(float _value, ValueType _type)
	{
		m_top.value = _value;
		m_top.type = _type;
		m_topDirty = true;
	}

	void PositionProperty::setTop(float _value)
	{
		m_top.value = _value;
		m_topDirty = true;
	}

	void PositionProperty::resetTop()
	{
		m_top = Value();
		m_topDirty = false;
	}

	void PositionProperty::setTopFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetTop();
			return;
		}

		if (std::strcmp(_value, "auto") == 0)
		{
			setTop(Value{ 0.f, ValueType::Auto });
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setTop(val, ValueType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setTop(val, ValueType::Percentage);
		}
		else
		{
			resetTop();
		}
	}

	const PositionProperty::Value& PositionProperty::getRight() const
	{
		return m_right;
	}

	void PositionProperty::setRight(const Value& _value)
	{
		m_right = _value;
		m_rightDirty = true;
	}

	void PositionProperty::setRight(float _value, ValueType _type)
	{
		m_right.value = _value;
		m_right.type = _type;
		m_rightDirty = true;
	}

	void PositionProperty::setRight(float _value)
	{
		m_right.value = _value;
		m_rightDirty = true;
	}

	void PositionProperty::resetRight()
	{
		m_right = Value();
		m_rightDirty = false;
	}

	void PositionProperty::setRightFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetRight();
			return;
		}

		if (std::strcmp(_value, "auto") == 0)
		{
			setRight(Value{ 0.f, ValueType::Auto });
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setRight(val, ValueType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setRight(val, ValueType::Percentage);
		}
		else
		{
			resetRight();
		}
	}

	const PositionProperty::Value& PositionProperty::getBottom() const
	{
		return m_bottom;
	}

	void PositionProperty::setBottom(const Value& _value)
	{
		m_bottom = _value;
		m_bottomDirty = true;
	}

	void PositionProperty::setBottom(float _value, ValueType _type)
	{
		m_bottom.value = _value;
		m_bottom.type = _type;
		m_bottomDirty = true;
	}

	void PositionProperty::setBottom(float _value)
	{
		m_bottom.value = _value;
		m_bottomDirty = true;
	}

	void PositionProperty::resetBottom()
	{
		m_bottom = Value();
		m_bottomDirty = false;
	}

	void PositionProperty::setBottomFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetBottom();
			return;
		}

		if (std::strcmp(_value, "auto") == 0)
		{
			setBottom(Value{ 0.f, ValueType::Auto });
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setBottom(val, ValueType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setBottom(val, ValueType::Percentage);
		}
		else
		{
			resetBottom();
		}
	}

	const PositionProperty::Value& PositionProperty::getLeft() const
	{
		return m_left;
	}

	void PositionProperty::setLeft(const Value& _value)
	{
		m_left = _value;
		m_leftDirty = true;
	}

	void PositionProperty::setLeft(float _value, ValueType _type)
	{
		m_left.value = _value;
		m_left.type = _type;
		m_leftDirty = true;
	}

	void PositionProperty::setLeft(float _value)
	{
		m_left.value = _value;
		m_leftDirty = true;
	}

	void PositionProperty::resetLeft()
	{
		m_left = Value();
		m_leftDirty = false;
	}
	void PositionProperty::setLeftFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetLeft();
			return;
		}

		if (std::strcmp(_value, "auto") == 0)
		{
			setLeft(Value{ 0.f, ValueType::Auto });
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setLeft(val, ValueType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setLeft(val, ValueType::Percentage);
		}
		else
		{
			resetLeft();
		}
	}
}
