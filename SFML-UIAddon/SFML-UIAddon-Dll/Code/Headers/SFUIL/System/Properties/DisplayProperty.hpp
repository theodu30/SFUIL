#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API DisplayProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class Type : char
		{
			Flex,
			None
		};

		[[nodiscard]] Type getDisplay() const;
		void setDisplay(Type _type);
		void resetDisplay();

	private:
		Type m_display = Type::Flex;
		bool m_displayDirty = false;
	};
}