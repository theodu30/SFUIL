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

				std::cout << "Importing element of type: " << elementType << std::endl;

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
		size_t pos = 0;
		while (pos < _styleString.length())
		{
			size_t colonPos = _styleString.find(':', pos);
			if (colonPos == std::string::npos)
			{
				break;
			}
			size_t semicolonPos = _styleString.find(';', colonPos);
			if (semicolonPos == std::string::npos)
			{
				semicolonPos = _styleString.length();
			}
			std::string propertyName = _styleString.substr(pos, colonPos - pos);
			std::string propertyValue = _styleString.substr(colonPos + 1, semicolonPos - colonPos - 1);
			// Trim whitespace
			propertyName.erase(0, propertyName.find_first_not_of(" \t"));
			propertyName.erase(propertyName.find_last_not_of(" \t") + 1);
			propertyValue.erase(0, propertyValue.find_first_not_of(" \t"));
			propertyValue.erase(propertyValue.find_last_not_of(" \t") + 1);

			if (strcmp(propertyName.c_str(), "align-items") == 0)
			{
				_element->getProperty<AlignProperty>().setAlignItemsFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "justify-content") == 0)
			{
				_element->getProperty<AlignProperty>().setJustifyContentFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "align-self") == 0)
			{
				_element->getProperty<AlignProperty>().setAlignSelfFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "align-content") == 0)
			{
				_element->getProperty<AlignProperty>().setAlignContentFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "background-color") == 0)
			{
				_element->getProperty<BackgroundProperty>().setColorFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "border-color") == 0)
			{
				_element->getProperty<BorderProperty>().setColorFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "border-width") == 0)
			{
				_element->getProperty<BorderProperty>().setWidthFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "border-radius") == 0)
			{
				_element->getProperty<BorderProperty>().setRadiusFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "display") == 0)
			{
				_element->getProperty<DisplayProperty>().setDisplayFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "flex-basic") == 0)
			{
				_element->getProperty<FlexProperty>().setFlexBasicFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "flex-shrink") == 0)
			{
				_element->getProperty<FlexProperty>().setFlexShrinkFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "flex-grow") == 0)
			{
				_element->getProperty<FlexProperty>().setFlexGrowFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "flex-direction") == 0)
			{
				_element->getProperty<FlexProperty>().setFlexDirectionFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "flex-wrap") == 0)
			{
				_element->getProperty<FlexProperty>().setFlexWrapFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "opacity") == 0)
			{
				_element->getProperty<OpacityProperty>().setOpacityFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "position") == 0)
			{
				_element->getProperty<PositionProperty>().setModeFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "top") == 0)
			{
				_element->getProperty<PositionProperty>().setTopFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "right") == 0)
			{
				_element->getProperty<PositionProperty>().setRightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "bottom") == 0)
			{
				_element->getProperty<PositionProperty>().setBottomFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "left") == 0)
			{
				_element->getProperty<PositionProperty>().setLeftFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "width") == 0)
			{
				_element->getProperty<SizeProperty>().setWidthFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "height") == 0)
			{
				_element->getProperty<SizeProperty>().setHeightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "min-width") == 0)
			{
				_element->getProperty<SizeProperty>().setMinWidthFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "min-height") == 0)
			{
				_element->getProperty<SizeProperty>().setMinHeightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "max-width") == 0)
			{
				_element->getProperty<SizeProperty>().setMaxWidthFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "max-height") == 0)
			{
				_element->getProperty<SizeProperty>().setMaxHeightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "margin-top") == 0)
			{
				_element->getProperty<SpacingProperty>().setMarginTopFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "margin-right") == 0)
			{
				_element->getProperty<SpacingProperty>().setMarginRightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "margin-bottom") == 0)
			{
				_element->getProperty<SpacingProperty>().setMarginBottomFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "margin-left") == 0)
			{
				_element->getProperty<SpacingProperty>().setMarginLeftFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "padding-top") == 0)
			{
				_element->getProperty<SpacingProperty>().setPaddingTopFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "padding-right") == 0)
			{
				_element->getProperty<SpacingProperty>().setPaddingRightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "padding-bottom") == 0)
			{
				_element->getProperty<SpacingProperty>().setPaddingBottomFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "padding-left") == 0)
			{
				_element->getProperty<SpacingProperty>().setPaddingLeftFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "origin-x") == 0)
			{
				_element->getProperty<TransformProperty>().setOriginXFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "origin-y") == 0)
			{
				_element->getProperty<TransformProperty>().setOriginYFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "scale-x") == 0)
			{
				_element->getProperty<TransformProperty>().setScaleXFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "scale-y") == 0)
			{
				_element->getProperty<TransformProperty>().setScaleYFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "rotate") == 0)
			{
				_element->getProperty<TransformProperty>().setRotateFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "visibility") == 0)
			{
				_element->getProperty<VisibilityProperty>().setVisibilityFromCStr(propertyValue.c_str());
			}

			pos = semicolonPos + 1;
		}
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
		parseAndSetProperty_UIVisualContainer(_element, _styleString);
		size_t pos = 0;
		while (pos < _styleString.length())
		{
			size_t colonPos = _styleString.find(':', pos);
			if (colonPos == std::string::npos)
			{
				break;
			}
			size_t semicolonPos = _styleString.find(';', colonPos);
			if (semicolonPos == std::string::npos)
			{
				semicolonPos = _styleString.length();
			}
			std::string propertyName = _styleString.substr(pos, colonPos - pos);
			std::string propertyValue = _styleString.substr(colonPos + 1, semicolonPos - colonPos - 1);
			// Trim whitespace
			propertyName.erase(0, propertyName.find_first_not_of(" \t"));
			propertyName.erase(propertyName.find_last_not_of(" \t") + 1);
			propertyValue.erase(0, propertyValue.find_first_not_of(" \t"));
			propertyValue.erase(propertyValue.find_last_not_of(" \t") + 1);

			if (strcmp(propertyName.c_str(), "image-repeat") == 0)
			{
				_element->getProperty<ImageProperty>().setRepeatFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-smooth") == 0)
			{
				_element->getProperty<ImageProperty>().setSmoothFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-path") == 0)
			{
				_element->getProperty<ImageProperty>().setImagePathFromCStr(propertyValue.c_str());
				_element->getProperty<ImageProperty>().loadImage();
			}
			else if (strcmp(propertyName.c_str(), "image-tint") == 0)
			{
				_element->getProperty<ImageProperty>().setTintColorFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-width") == 0)
			{
				_element->getProperty<ImageProperty>().setWidthFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-height") == 0)
			{
				_element->getProperty<ImageProperty>().setHeightFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-position-x") == 0)
			{
				_element->getProperty<ImageProperty>().setPositionXFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-position-y") == 0)
			{
				_element->getProperty<ImageProperty>().setPositionYFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-position-x-offset") == 0)
			{
				_element->getProperty<ImageProperty>().setPositionXOffsetFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-position-y-offset") == 0)
			{
				_element->getProperty<ImageProperty>().setPositionYOffsetFromCStr(propertyValue.c_str());
			}
			else if (strcmp(propertyName.c_str(), "image-scale-mode") == 0)
			{
				_element->getProperty<ImageProperty>().setScaleModeFromCStr(propertyValue.c_str());
			}

			pos = semicolonPos + 1;
		}
	}

}
