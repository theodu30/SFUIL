#pragma once

#include "../Exports.hpp"
#include <ostream>

namespace sfui
{
	// Forward declaration
	class UIElement;

	class SFUIL_API Property
	{
	public:
		virtual void exportToXML(std::ostream& _stream) const = 0;
	};
}