#include "Headers/SFUIL/XMLExport.hpp"
#include "Headers/SFUIL/UIElement.hpp"
#include "Headers/SFUIL/Containers/UIVisualContainer.hpp"
#include "Headers/SFUIL/Containers/UIImage.hpp"
#include "Headers/SFUIL/UIPanel.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

namespace sfui
{
	void XMLExport::exportToXML(UIElement* _element, const char* _filename)
	{
		// Create file using filename and extension
		std::ofstream file(std::string(_filename) + ".xml", std::ios::out | std::ios::trunc);
		if (!file.is_open())
		{
			std::cerr << "Failed to open file for XML export: " << _filename << std::endl;
			return;
		}

		exportElement_UIVisualContainer_ToXML(_element->as<UIVisualContainer>(), file, 0);

		file.close();
	}

	void XMLExport::exportElement_UIVisualContainer_ToXML(UIVisualContainer* _element, std::ostream& _stream, int _indentLevel)
	{
		_stream << std::string(_indentLevel, '\t');
		_stream << "<sfui:" << _element->getTypeName();

		if (std::strcmp(_element->getName(), _element->getTypeName()) != 0)
		{
			_stream << " name=\"" << _element->getName() << "\"";
		}

		bool hasChild = _element->getChildCount() > 0;

		_stream << (!hasChild ? "/>" : ">") << std::endl;

		for (auto& child : _element->getChildren())
		{
			exportElement_UIVisualContainer_ToXML(child->as<UIVisualContainer>(), _stream, _indentLevel + 1);
		}

		if (hasChild)
		{
			_stream << std::string(_indentLevel, '\t');
			_stream << "</sfui:" << _element->getTypeName() << ">" << std::endl;
		}
	}

	void XMLExport::exportElement_UIImage_ToXML(UIImage* _element, std::ostream& _stream, int _indentLevel)
	{
	}
}
