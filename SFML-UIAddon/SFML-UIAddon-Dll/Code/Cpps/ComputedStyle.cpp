#include "../Headers/SFUIL/System/Styles/ComputedStyle.hpp"

namespace sfui
{
	AlignEnum ComputedStyle::getAlignContent() const
	{
		return layoutData.Read().alignContent;
	}

	AlignEnum ComputedStyle::getAlignItems() const
	{
		return layoutData.Read().alignItems;
	}

	AlignEnum ComputedStyle::getAlignSelf() const
	{
		return layoutData.Read().alignSelf;
	}

	sf::Color ComputedStyle::getBackgroundColor() const
	{
		return visualData.Read().backgroundColor;
	}

	std::string ComputedStyle::getTextureKey() const
	{
		return visualData.Read().textureKey;
	}

	BackgroundPosition ComputedStyle::getBackgroundPositionX() const
	{
		return visualData.Read().backgroundPositionX;
	}

	BackgroundPosition ComputedStyle::getBackgroundPositionY() const
	{
		return visualData.Read().backgroundPositionY;
	}

	bool ComputedStyle::getBackgroundRepeat() const
	{
		return visualData.Read().backgroundRepeat;
	}

	bool ComputedStyle::getBackgroundSmooth() const
	{
		return visualData.Read().backgroundSmooth;
	}

	BackgroundSize ComputedStyle::getBackgroundSize() const
	{
		return visualData.Read().backgroundSize;
	}

	sf::Color ComputedStyle::getBorderColor() const
	{
		return visualData.Read().borderColor;
	}

	Length ComputedStyle::getBorderRadius() const
	{
		return visualData.Read().borderRadius;
	}

	float ComputedStyle::getBorderWidth() const
	{
		return layoutData.Read().borderWidth;
	}

	Length ComputedStyle::getBottom() const
	{
		return layoutData.Read().bottom;
	}

	sf::Color ComputedStyle::getColor() const
	{
		return inheritedData.Read().textColor;
	}

	DisplayEnum ComputedStyle::getDisplay() const
	{
		return layoutData.Read().display;
	}

	Length ComputedStyle::getFlexBasis() const
	{
		return layoutData.Read().flexBasis;
	}

	FlexDirectionEnum ComputedStyle::getFlexDirection() const
	{
		return layoutData.Read().flexDirection;
	}

	float ComputedStyle::getFlexGrow() const
	{
		return layoutData.Read().flexGrow;
	}

	float ComputedStyle::getFlexShrink() const
	{
		return layoutData.Read().flexShrink;
	}

	FlexWrapEnum ComputedStyle::getFlexWrap() const
	{
		return layoutData.Read().flexWrap;
	}

	Length ComputedStyle::getFontSize() const
	{
		return inheritedData.Read().fontSize;
	}

	Length ComputedStyle::getHeight() const
	{
		return layoutData.Read().height;
	}

	JustifyEnum ComputedStyle::getJustifyContent() const
	{
		return layoutData.Read().justifyContent;
	}

	Length ComputedStyle::getLeft() const
	{
		return layoutData.Read().left;
	}

	Length ComputedStyle::getMarginBottom() const
	{
		return layoutData.Read().marginBottom;
	}

	Length ComputedStyle::getMarginLeft() const
	{
		return layoutData.Read().marginLeft;
	}

	Length ComputedStyle::getMarginRight() const
	{
		return layoutData.Read().marginRight;
	}

	Length ComputedStyle::getMarginTop() const
	{
		return layoutData.Read().marginTop;
	}

	Length ComputedStyle::getMaxHeight() const
	{
		return layoutData.Read().maxHeight;
	}

	Length ComputedStyle::getMaxWidth() const
	{
		return layoutData.Read().maxWidth;
	}

	Length ComputedStyle::getMinHeight() const
	{
		return layoutData.Read().minHeight;
	}

	Length ComputedStyle::getMinWidth() const
	{
		return layoutData.Read().minWidth;
	}

	float ComputedStyle::getOpacity() const
	{
		return visualData.Read().opacity;
	}

	Length ComputedStyle::getPaddingBottom() const
	{
		return layoutData.Read().paddingBottom;
	}

	Length ComputedStyle::getPaddingLeft() const
	{
		return layoutData.Read().paddingLeft;
	}

	Length ComputedStyle::getPaddingRight() const
	{
		return layoutData.Read().paddingRight;
	}

	Length ComputedStyle::getPaddingTop() const
	{
		return layoutData.Read().paddingTop;
	}

	PositionEnum ComputedStyle::getPosition() const
	{
		return layoutData.Read().position;
	}

	Length ComputedStyle::getRight() const
	{
		return layoutData.Read().right;
	}

	sf::Angle ComputedStyle::getRotate() const
	{
		return transformData.Read().rotate;
	}

	sf::Vector2f ComputedStyle::getScale() const
	{
		return transformData.Read().scale;
	}

	Length ComputedStyle::getTop() const
	{
		return layoutData.Read().top;
	}

	TransformOrigin ComputedStyle::getTransformOrigin() const
	{
		return transformData.Read().transformOrigin;
	}

	TransformTranslate ComputedStyle::getTranslate() const
	{
		return transformData.Read().translate;
	}

	sf::Color ComputedStyle::getBackgroundImageTint() const
	{
		return visualData.Read().backgroundImageTint;
	}

	sf::Font ComputedStyle::getTextFont() const
	{
		return inheritedData.Read().textFont;
	}

	FontStyleEnum ComputedStyle::getFontStyle() const
	{
		return inheritedData.Read().fontStyle;
	}

	TextAlignEnum ComputedStyle::getTextAlign() const
	{
		return inheritedData.Read().textAlign;
	}

	VisibilityEnum ComputedStyle::getVisibility() const
	{
		return inheritedData.Read().visibility;
	}

	Length ComputedStyle::getWidth() const
	{
		return layoutData.Read().width;
	}

	ComputedStyle ComputedStyle::create()
	{
		return InitialStyle::acquire();
	}

	ComputedStyle ComputedStyle::create(ComputedStyle& _parentStyle)
	{
		ComputedStyle& reference = InitialStyle::get();
		ComputedStyle result;
		result.inheritedData = _parentStyle.inheritedData.Acquire();
		result.layoutData = reference.layoutData.Acquire();
		result.transformData = reference.transformData.Acquire();
		result.visualData = reference.visualData.Acquire();
		return result;
	}

	ComputedStyle ComputedStyle::createInitial()
	{
		ComputedStyle result;
		result.inheritedData = StyleDataRef<InheritedData>::Create();
		result.layoutData = StyleDataRef<LayoutData>::Create();
		result.transformData = StyleDataRef<TransformData>::Create();
		result.visualData = StyleDataRef<VisualData>::Create();
		return result;
	}

	ComputedStyle ComputedStyle::acquire()
	{
		inheritedData.Acquire();
		layoutData.Acquire();
		transformData.Acquire();
		visualData.Acquire();
		return *this;
	}

	void ComputedStyle::release()
	{
		inheritedData.Release();
		layoutData.Release();
		transformData.Release();
		visualData.Release();
	}

	AlignEnum InitialStyle::getAlignContent()
	{
		return;
	}

	AlignEnum InitialStyle::getAlignItems()
	{
		return;
	}

	AlignEnum InitialStyle::getAlignSelf()
	{
		return;
	}

	sf::Color InitialStyle::getBackgroundColor()
	{
		return;
	}

	std::string InitialStyle::getTextureKey()
	{
		return;
	}

	BackgroundPosition InitialStyle::getBackgroundPositionX()
	{
		return;
	}

	BackgroundPosition InitialStyle::getBackgroundPositionY()
	{
		return;
	}

	bool InitialStyle::getBackgroundRepeat()
	{
		return;
	}

	bool InitialStyle::getBackgroundSmooth()
	{
		return;
	}

	BackgroundSize InitialStyle::getBackgroundSize()
	{
		return;
	}

	sf::Color InitialStyle::getBorderColor()
	{
		return;
	}

	Length InitialStyle::getBorderRadius()
	{
		return;
	}

	float InitialStyle::getBorderWidth()
	{
		return;
	}

	Length InitialStyle::getBottom()
	{
		return;
	}

	sf::Color InitialStyle::getColor()
	{
		return;
	}

	DisplayEnum InitialStyle::getDisplay()
	{
		return;
	}

	Length InitialStyle::getFlexBasis()
	{
		return;
	}

	FlexDirectionEnum InitialStyle::getFlexDirection()
	{
		return;
	}

	float InitialStyle::getFlexGrow()
	{
		return;
	}

	float InitialStyle::getFlexShrink()
	{
		return;
	}

	FlexWrapEnum InitialStyle::getFlexWrap()
	{
		return;
	}

	Length InitialStyle::getFontSize()
	{
		return;
	}

	Length InitialStyle::getHeight()
	{
		return;
	}

	JustifyEnum InitialStyle::getJustifyContent()
	{
		return;
	}

	Length InitialStyle::getLeft()
	{
		return;
	}

	Length InitialStyle::getMarginBottom()
	{
		return;
	}

	Length InitialStyle::getMarginLeft()
	{
		return;
	}

	Length InitialStyle::getMarginRight()
	{
		return;
	}

	Length InitialStyle::getMarginTop()
	{
		return;
	}

	Length InitialStyle::getMaxHeight()
	{
		return;
	}

	Length InitialStyle::getMaxWidth()
	{
		return;
	}

	Length InitialStyle::getMinHeight()
	{
		return;
	}

	Length InitialStyle::getMinWidth()
	{
		return;
	}

	float InitialStyle::getOpacity()
	{
		return;
	}

	Length InitialStyle::getPaddingBottom()
	{
		return;
	}

	Length InitialStyle::getPaddingLeft()
	{
		return;
	}

	Length InitialStyle::getPaddingRight()
	{
		return;
	}

	Length InitialStyle::getPaddingTop()
	{
		return;
	}

	PositionEnum InitialStyle::getPosition()
	{
		return;
	}

	Length InitialStyle::getRight()
	{
		return;
	}

	sf::Angle InitialStyle::getRotate()
	{
		return;
	}

	sf::Vector2f InitialStyle::getScale()
	{
		return;
	}

	Length InitialStyle::getTop()
	{
		return;
	}

	TransformOrigin InitialStyle::getTransformOrigin()
	{
		return;
	}

	TransformTranslate InitialStyle::getTranslate()
	{
		return;
	}

	sf::Color InitialStyle::getBackgroundImageTint()
	{
		return;
	}

	sf::Font InitialStyle::getTextFont()
	{
		return;
	}

	FontStyleEnum InitialStyle::getFontStyle()
	{
		return;
	}

	TextAlignEnum InitialStyle::getTextAlign()
	{
		return;
	}

	VisibilityEnum InitialStyle::getVisibility()
	{
		return;
	}

	Length InitialStyle::getWidth()
	{
		return;
	}

	ComputedStyle& InitialStyle::get()
	{
		return;
	}

	ComputedStyle InitialStyle::acquire()
	{
		return;
	}

}