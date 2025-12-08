#include "../../Headers/SFUIL/System/Properties/PositionProperty.hpp"

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
}
