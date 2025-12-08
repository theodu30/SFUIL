#include "../../Headers/SFUIL/System/Properties/VisibilityProperty.hpp"

namespace sfui
{
	void VisibilityProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_visibilityDirty)
		{
			switch (m_visibility)
			{
			case Type::Visible: _stream << "visibility: visible; "; break;
			case Type::Hidden: _stream << "visibility: hidden; "; break;
			default: break;
			}
		}
	}

	VisibilityProperty::Type VisibilityProperty::getVisibility() const
	{
		return Type();
	}

	void VisibilityProperty::setVisibility(Type _type)
	{
		m_visibility = _type;
		m_visibilityDirty = true;
	}

	void VisibilityProperty::resetVisibility()
	{
		m_visibility = Type::Visible;
		m_visibilityDirty = false;
	}
}
