#include "../../Headers/SFUIL/System/Properties/OpacityProperty.hpp"
#include "../../Headers/SFUIL/System/UIPropUtils.hpp"

namespace sfui
{
	void OpacityProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_opacityDirty)
		{
			_stream << "opacity: " << m_opacity << "; ";
		}
	}

	const float& OpacityProperty::getOpacity() const
	{
		return m_opacity;
	}

	void OpacityProperty::setOpacity(float _opacity)
	{
		// Clamp the value between 0.0f and 1.0f
		m_opacity = UIPropUtils::clampFloat(_opacity, 0.0f, 1.0f);
		m_opacityDirty = true;
	}

	void OpacityProperty::resetOpacity()
	{
		m_opacity = 1.f;
		m_opacityDirty = false;
	}
}
