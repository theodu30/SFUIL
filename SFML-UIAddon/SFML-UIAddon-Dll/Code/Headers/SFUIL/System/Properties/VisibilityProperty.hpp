#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API VisibilityProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class Type : char
		{
			Visible,
			Hidden
		};
		[[nodiscard]] Type getVisibility() const;
		void setVisibility(Type _type);
		void resetVisibility();
		void setVisibilityFromCStr(const char* _value);

	private:
		Type m_visibility = Type::Visible;
		bool m_visibilityDirty = false;
	};
}