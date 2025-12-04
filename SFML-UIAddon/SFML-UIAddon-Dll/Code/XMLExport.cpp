#include "Headers/SFUIL/XMLExport.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

namespace sfui
{
	void XMLExport::exportToXML(const UIElement* element, const char* filename)
	{
		// Create file using filename and extension
		std::ofstream file(std::string(filename) + ".xml", std::ios::out | std::ios::trunc);
		if (!file.is_open())
		{
			std::cerr << "Failed to open file for XML export: " << filename << std::endl;
			return;
		}
	}
}
