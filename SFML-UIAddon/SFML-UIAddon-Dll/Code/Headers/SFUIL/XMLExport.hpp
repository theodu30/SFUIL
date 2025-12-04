#pragma once

#include "System/Exports.hpp"

namespace sfui
{
	// Forward declaration
	class UIElement;
	class SFUIL_API XMLExport
	{
	public:
		static void exportToXML(const UIElement* element, const char* filename);
	};
}