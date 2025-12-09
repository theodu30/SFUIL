#pragma once

#include "System/Exports.hpp"
#include <string>

namespace sfui
{
	class SFUIL_API XMLImport
	{
	public:
		static class UIElement* importFromXML(const char* _filename);

	private:
		static class UIVisualContainer* importElement_UIVisualContainer_FromXML(const std::string& _elementString);
		static void parseAndSetProperty_UIVisualContainer(class UIVisualContainer* _element, const std::string& _styleString);

		static class UIImage* importElement_UIImage_FromXML(const std::string& _elementString);
		static void parseAndSetProperty_UIImage(class UIImage* _element, const std::string& _styleString);
	};
}