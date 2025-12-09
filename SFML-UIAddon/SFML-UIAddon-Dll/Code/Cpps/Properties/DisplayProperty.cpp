#include "../../Headers/SFUIL/System/Properties/DisplayProperty.hpp"

namespace sfui
{
	void DisplayProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_displayDirty)
		{
			switch (m_display)
			{
			case Type::Flex: _stream << "display: flex; "; break;
			case Type::None: _stream << "display: none; "; break;
			default: break;
			}
		}
	}

	DisplayProperty::Type DisplayProperty::getDisplay() const
	{
		return m_display;
	}

	void DisplayProperty::setDisplay(Type _type)
	{
		m_display = _type;
		m_displayDirty = true;
	}

	void DisplayProperty::resetDisplay()
	{
		m_display = Type::Flex;
		m_displayDirty = false;
	}

	void DisplayProperty::setDisplayFromCStr(const char* _typeStr)
	{
		if (_typeStr == nullptr)
		{
			resetDisplay();
			return;
		}

		if (strcmp(_typeStr, "flex") == 0)
		{
			setDisplay(Type::Flex);
		}
		else if (strcmp(_typeStr, "none") == 0)
		{
			setDisplay(Type::None);
		}
		else
		{
			resetDisplay();
		}
	}

}
