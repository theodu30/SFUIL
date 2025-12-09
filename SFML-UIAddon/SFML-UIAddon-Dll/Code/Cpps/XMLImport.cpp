#include "../Headers/SFUIL/XMLImport.hpp"
#include "../Headers/SFUIL/UIElement.hpp"
#include "../Headers/SFUIL/Containers/UIVisualContainer.hpp"
#include "../Headers/SFUIL/Containers/UIImage.hpp"
#include <istream>
#include <fstream>
#include <iostream>

namespace sfui
{
	UIElement* XMLImport::importFromXML(const char* _filename)
	{
		// Open file using filename
		std::ifstream file(std::string(_filename), std::ios::in);
		if (!file.is_open())
		{
			std::cerr << "Failed to open file for XML import: " << _filename << std::endl;
			return nullptr;
		}

		UIElement* rootElement = nullptr;
		int indentLevel = 0;

		int lineNumber = 1;

		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);

			size_t firstNonWhitespace = line.find_first_not_of(" \t");
			if (firstNonWhitespace == std::string::npos)
			{
				continue;
			}

			std::string trimmedLine = line.substr(firstNonWhitespace);
			std::string startTag = "<sfui:";
			std::string endTag = "</sfui:";

			if (trimmedLine.rfind(startTag, 0) == 0)
			{
				size_t typeEnd = trimmedLine.find_first_of(" >", startTag.length());
				std::string elementType = trimmedLine.substr(6, typeEnd - 6);
				std::string lineAfterType = trimmedLine.substr(typeEnd);

				UIElement* element = nullptr;

				if (strcmp(elementType.c_str(), UIVisualContainer::staticTypeName()) == 0)
				{
					element = importElement_UIVisualContainer_FromXML(lineAfterType);
				}
				else if (strcmp(elementType.c_str(), UIImage::staticTypeName()) == 0)
				{
					element = importElement_UIImage_FromXML(lineAfterType);
				}

				if (element != nullptr)
				{
					bool isRoot = (rootElement == nullptr);

					std::string closingTag = "/>";
					if (lineAfterType.find(closingTag) == std::string::npos)
					{
						if (lineAfterType.back() != '>')
						{
							std::cerr << "Line " << lineNumber << ": Malformed XML: Expected '>' at end of line for element with children." << std::endl;
							delete element;
							continue;
						}
						indentLevel++;
						if (isRoot)
						{
							rootElement = element;
						}
						else
						{
							rootElement->addChild(element);
							rootElement = element;
						}
					}
					else
					{
						if (lineAfterType.substr(lineAfterType.length() - 2) != "/>")
						{
							std::cerr << "Line " << lineNumber << ": Malformed XML: Expected '/>' at end of line for self-closing element." << std::endl;
							delete element;
							continue;
						}

						if (indentLevel == 0)
						{
							std::cerr << "Line " << lineNumber << ": Malformed XML: Unexpected self-closing tag at root level." << std::endl;
							delete element;
							continue;
						}

						rootElement->addChild(element);
					}
				}
				else
				{
					std::cerr << "Line " << lineNumber << ": Unknown element type: \"" << elementType << "\"" << std::endl;
					continue;
				}
			}
			else if (trimmedLine.rfind(endTag, 0) == 0)
			{
				indentLevel--;
				if (indentLevel < 0)
				{
					std::cerr << "Line " << lineNumber << ": Malformed XML: Unexpected closing tag without matching opening tag." << std::endl;
					indentLevel = 0;
				}

				// Move up to parent element
				if (rootElement != nullptr)
				{
					UIElement* parent = rootElement->getParent();
					if (parent != nullptr)
					{
						rootElement = parent;
					}
				}
			}
			lineNumber++;
		}

		file.close();
		return rootElement;
	}

	UIVisualContainer* XMLImport::importElement_UIVisualContainer_FromXML(const std::string& _elementString)
	{
		UIVisualContainer* element = nullptr;

		std::string nameAttr = "name=\"";
		size_t namePos = _elementString.find(nameAttr);
		if (namePos != std::string::npos)
		{
			size_t nameStart = namePos + nameAttr.length();
			size_t nameEnd = _elementString.find("\"", nameStart);
			if (nameEnd != std::string::npos)
			{
				std::string nameValue = _elementString.substr(nameStart, nameEnd - nameStart);
				element = new UIVisualContainer(nameValue.c_str());
			}
		}
		else
		{
			element = new UIVisualContainer();
		}

		std::string styleAttr = "style=\"";
		size_t stylePos = _elementString.find(styleAttr);
		if (stylePos != std::string::npos)
		{
			size_t styleStart = stylePos + styleAttr.length();
			size_t styleEnd = _elementString.find("\"", styleStart);
			if (styleEnd != std::string::npos)
			{
				std::string styleValue = _elementString.substr(styleStart, styleEnd - styleStart);
				parseAndSetProperty_UIVisualContainer(element, styleValue);
			}
		}

		return element;
	}

	void XMLImport::parseAndSetProperty_UIVisualContainer(UIVisualContainer* _element, const std::string& _styleString)
	{
		//std::cout << "Parsing style for UIVisualContainer: " << _styleString << std::endl;
	}

	UIImage* XMLImport::importElement_UIImage_FromXML(const std::string& _elementString)
	{
		UIImage* element = nullptr;

		std::string nameAttr = "name=\"";
		size_t namePos = _elementString.find(nameAttr);
		if (namePos != std::string::npos)
		{
			size_t nameStart = namePos + nameAttr.length();
			size_t nameEnd = _elementString.find("\"", nameStart);
			if (nameEnd != std::string::npos)
			{
				std::string nameValue = _elementString.substr(nameStart, nameEnd - nameStart);
				element = new UIImage(nameValue.c_str());
			}
		}
		else
		{
			element = new UIImage();
		}

		std::string styleAttr = "style=\"";
		size_t stylePos = _elementString.find(styleAttr);
		if (stylePos != std::string::npos)
		{
			size_t styleStart = stylePos + styleAttr.length();
			size_t styleEnd = _elementString.find("\"", styleStart);
			if (styleEnd != std::string::npos)
			{
				std::string styleValue = _elementString.substr(styleStart, styleEnd - styleStart);
				parseAndSetProperty_UIImage(element, styleValue);
			}
		}

		return element;
	}

	void XMLImport::parseAndSetProperty_UIImage(UIImage* _element, const std::string& _styleString)
	{
		//std::cout << "Parsing style for UIImage: " << _styleString << std::endl;
	}

}
