#pragma once

#include "System/Exports.hpp"
#include <ostream>

namespace sfui
{
	class SFUIL_API XMLExport
	{
	public:
		static void exportToXML(class UIElement* _element, const char* _filename);
	
	private:
		// UIElements exporter
		static void exportElement_UIVisualContainer_ToXML(class UIVisualContainer* _element, std::ostream& _stream, int _indentLevel);
		static void exportElement_UIImage_ToXML(class UIImage* _element, std::ostream& _stream, int _indentLevel);
	};
}