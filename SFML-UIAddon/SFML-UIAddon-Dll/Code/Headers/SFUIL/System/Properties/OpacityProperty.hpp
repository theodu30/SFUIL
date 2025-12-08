#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API OpacityProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		[[nodiscard]] const float& getOpacity() const;
		void setOpacity(float _opacity);
		void resetOpacity();

	private:
		float m_opacity = 1.f;
		bool m_opacityDirty = false;
	};
}