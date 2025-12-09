#include "../../Headers/SFUIL/System/Properties/FlexProperty.hpp"
#include <string>

namespace sfui
{
	float FlexProperty::Basic::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case BasicType::Auto:
			return 0.f;
		case BasicType::Pixels:
			return value;
		case BasicType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	void FlexProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_flexBasisDirty)
		{
			switch (m_flexBasis.type)
			{
			case BasicType::Auto: _stream << "flex-basic: auto; "; break;
			case BasicType::Pixels: _stream << "flex-basic:" << m_flexBasis.value << "px; "; break;
			case BasicType::Percentage: _stream << "flex-basic:" << m_flexBasis.value << "%; "; break;
			default: break;
			}
		}

		if (m_flexShrinkDirty)
		{
			_stream << "flex-shrink: " << m_flexShrink << "; ";
		}

		if (m_flexGrowDirty)
		{
			_stream << "flex-grow: " << m_flexGrow << "; ";
		}

		if (m_flexDirectionDirty)
		{
			switch (m_flexDirection)
			{
			case Direction::Column: _stream << "flex-direction: column; "; break;
			case Direction::ColumnReverse: _stream << "flex-direction: column-reverse; "; break;
			case Direction::Row: _stream << "flex-direction: row; "; break;
			case Direction::RowReverse: _stream << "flex-direction: row-reverse; "; break;
			default: break;
			}
		}

		if (m_flexWrapDirty)
		{
			switch (m_flexWrap)
			{
			case Warp::NoWrap: _stream << "flex-wrap: no-wrap; "; break;
			case Warp::Wrap: _stream << "flex-wrap: wrap; "; break;
			case Warp::WrapReverse: _stream << "flex-wrap: wrap-reverse; "; break;
			default: break;
			}
		}
	}

	const FlexProperty::Basic& FlexProperty::getFlexBasic() const
	{
		return m_flexBasis;
	}

	void FlexProperty::setFlexBasic(const Basic& _value)
	{
		m_flexBasis = _value;
		m_flexBasisDirty = true;
	}

	void FlexProperty::setFlexBasic(float _value, BasicType _type)
	{
		m_flexBasis.value = _value;
		m_flexBasis.type = _type;
		m_flexBasisDirty = true;
	}

	void FlexProperty::setFlexBasic(float _value)
	{
		m_flexBasis.value = _value;
		m_flexBasisDirty = true;
	}

	void FlexProperty::resetFlexBasic()
	{
		m_flexBasis = Basic();
		m_flexBasisDirty = false;
	}

	void FlexProperty::setFlexBasicFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetFlexBasic();
			return;
		}

		if (std::strcmp(_value, "auto") == 0)
		{
			setFlexBasic(0.f, BasicType::Auto);
		}
		else if (std::strstr(_value, "px") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 2));
			setFlexBasic(val, BasicType::Pixels);
		}
		else if (std::strstr(_value, "%") != nullptr)
		{
			float val = std::stof(std::string(_value).substr(0, std::strlen(_value) - 1));
			setFlexBasic(val, BasicType::Percentage);
		}
		else
		{
			resetFlexBasic();
		}
	}

	const float& FlexProperty::getFlexShrink() const
	{
		return m_flexShrink;
	}

	void FlexProperty::setFlexShrink(float _value)
	{
		m_flexShrink = _value;
		m_flexShrinkDirty = true;
	}

	void FlexProperty::resetFlexShrink()
	{
		m_flexShrink = 1.f;
		m_flexShrinkDirty = false;
	}

	void FlexProperty::setFlexShrinkFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetFlexShrink();
			return;
		}

		try
		{
			float val = std::stof(_value);
			setFlexShrink(val);
		}
		catch (...)
		{
			resetFlexShrink();
		}
	}

	const float& FlexProperty::getFlexGrow() const
	{
		return m_flexGrow;
	}

	void FlexProperty::setFlexGrow(float _value)
	{
		m_flexGrow = _value;
		m_flexGrowDirty = true;
	}

	void FlexProperty::resetFlexGrow()
	{
		m_flexGrow = 1.f;
		m_flexGrowDirty = false;
	}

	void FlexProperty::setFlexGrowFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetFlexGrow();
			return;
		}

		try
		{
			float val = std::stof(_value);
			setFlexGrow(val);
		}
		catch (...)
		{
			resetFlexGrow();
		}
	}

	FlexProperty::Direction FlexProperty::getFlexDirection() const
	{
		return m_flexDirection;
	}

	void FlexProperty::setFlexDirection(Direction _direction)
	{
		m_flexDirection = _direction;
		m_flexDirectionDirty = true;
	}

	void FlexProperty::resetFlexDirection()
	{
		m_flexDirection = Direction::Column;
		m_flexDirectionDirty = false;
	}

	void FlexProperty::setFlexDirectionFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetFlexDirection();
			return;
		}

		if (std::strcmp(_value, "column") == 0)
		{
			setFlexDirection(Direction::Column);
		}
		else if (std::strcmp(_value, "column-reverse") == 0)
		{
			setFlexDirection(Direction::ColumnReverse);
		}
		else if (std::strcmp(_value, "row") == 0)
		{
			setFlexDirection(Direction::Row);
		}
		else if (std::strcmp(_value, "row-reverse") == 0)
		{
			setFlexDirection(Direction::RowReverse);
		}
		else
		{
			resetFlexDirection();
		}
	}

	FlexProperty::Warp FlexProperty::getFlexWrap() const
	{
		return m_flexWrap;
	}

	void FlexProperty::setFlexWrap(Warp _warp)
	{
		m_flexWrap = _warp;
		m_flexWrapDirty = true;
	}

	void FlexProperty::resetFlexWrap()
	{
		m_flexWrap = Warp::NoWrap;
		m_flexWrapDirty = false;
	}

	void FlexProperty::setFlexWrapFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetFlexWrap();
			return;
		}

		if (std::strcmp(_value, "no-wrap") == 0)
		{
			setFlexWrap(Warp::NoWrap);
		}
		else if (std::strcmp(_value, "wrap") == 0)
		{
			setFlexWrap(Warp::Wrap);
		}
		else if (std::strcmp(_value, "wrap-reverse") == 0)
		{
			setFlexWrap(Warp::WrapReverse);
		}
		else
		{
			resetFlexWrap();
		}
	}

}
