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

	ComputedStyle InitialStyle::m_initialStyle;

	InitialStyle::InitialStyle()
	{
		m_initialStyle = ComputedStyle::createInitial();
		m_initialStyle.layoutData.Write().alignContent = AlignEnum::FlexStart;
		m_initialStyle.layoutData.Write().alignItems = AlignEnum::Stretch;
		m_initialStyle.layoutData.Write().alignSelf = AlignEnum::Auto;
		m_initialStyle.visualData.Write().backgroundColor = sf::Color::Transparent;
		m_initialStyle.visualData.Write().textureKey = std::string();
		m_initialStyle.visualData.Write().backgroundPositionX = BackgroundPosition::Initial();
		m_initialStyle.visualData.Write().backgroundPositionY = BackgroundPosition::Initial();
		m_initialStyle.visualData.Write().backgroundRepeat = false;
		m_initialStyle.visualData.Write().backgroundSize = BackgroundSize::Initial();
		m_initialStyle.visualData.Write().borderColor = sf::Color::Transparent;
		m_initialStyle.visualData.Write().borderRadius = 0.f;
		m_initialStyle.layoutData.Write().borderWidth = 0.f;
		m_initialStyle.layoutData.Write().bottom = Length::Auto();
		m_initialStyle.inheritedData.Write().textColor = sf::Color::Black;
		m_initialStyle.layoutData.Write().display = DisplayEnum::Flex;
		m_initialStyle.layoutData.Write().flexBasis = Length::Auto();
		m_initialStyle.layoutData.Write().flexDirection = FlexDirectionEnum::Column;
		m_initialStyle.layoutData.Write().flexGrow = 0.f;
		m_initialStyle.layoutData.Write().flexShrink = 1.f;
		m_initialStyle.layoutData.Write().flexWrap = FlexWrapEnum::NoWrap;
		m_initialStyle.inheritedData.Write().fontSize = 14.f;
		m_initialStyle.layoutData.Write().height = Length::Auto();
		m_initialStyle.layoutData.Write().justifyContent = JustifyEnum::FlexStart;
		m_initialStyle.layoutData.Write().left = Length::Auto();
		m_initialStyle.layoutData.Write().marginBottom = 0.f;
		m_initialStyle.layoutData.Write().marginLeft = 0.f;
		m_initialStyle.layoutData.Write().marginRight = 0.f;
		m_initialStyle.layoutData.Write().marginTop = 0.f;
		m_initialStyle.layoutData.Write().maxHeight = Length::None();
		m_initialStyle.layoutData.Write().maxWidth = Length::None();
		m_initialStyle.layoutData.Write().minHeight = Length::Auto();
		m_initialStyle.layoutData.Write().minWidth = Length::Auto();
		m_initialStyle.visualData.Write().opacity = 1.f;
		m_initialStyle.layoutData.Write().paddingBottom = 0.f;
		m_initialStyle.layoutData.Write().paddingLeft = 0.f;
		m_initialStyle.layoutData.Write().paddingRight = 0.f;
		m_initialStyle.layoutData.Write().paddingTop = 0.f;
		m_initialStyle.layoutData.Write().position = PositionEnum::Relative;
		m_initialStyle.layoutData.Write().right = Length::Auto();
		m_initialStyle.transformData.Write().rotate = sf::degrees(0.f);
		m_initialStyle.transformData.Write().scale = sf::Vector2f(0.f, 0.f);
		m_initialStyle.layoutData.Write().top = Length::Auto();
		m_initialStyle.transformData.Write().transformOrigin = TransformOrigin::Initial();
		m_initialStyle.transformData.Write().translate = TransformTranslate::Initial();
		m_initialStyle.visualData.Write().backgroundImageTint = sf::Color::White;
		m_initialStyle.inheritedData.Write().textFont = sf::Font();
		m_initialStyle.inheritedData.Write().fontStyle = FontStyleEnum::Normal;
		m_initialStyle.inheritedData.Write().textAlign = TextAlignEnum::UpperLeft;
		m_initialStyle.inheritedData.Write().visibility = VisibilityEnum::Visible;
		m_initialStyle.layoutData.Write().width = Length::Auto();
	}

	AlignEnum InitialStyle::getAlignContent()
	{
		return m_initialStyle.layoutData.Read().alignContent;
	}

	AlignEnum InitialStyle::getAlignItems()
	{
		return m_initialStyle.layoutData.Read().alignItems;
	}

	AlignEnum InitialStyle::getAlignSelf()
	{
		return m_initialStyle.layoutData.Read().alignSelf;
	}

	sf::Color InitialStyle::getBackgroundColor()
	{
		return m_initialStyle.visualData.Read().backgroundColor;
	}

	std::string InitialStyle::getTextureKey()
	{
		return m_initialStyle.visualData.Read().textureKey;
	}

	BackgroundPosition InitialStyle::getBackgroundPositionX()
	{
		return m_initialStyle.visualData.Read().backgroundPositionX;
	}

	BackgroundPosition InitialStyle::getBackgroundPositionY()
	{
		return m_initialStyle.visualData.Read().backgroundPositionY;
	}

	bool InitialStyle::getBackgroundRepeat()
	{
		return m_initialStyle.visualData.Read().backgroundRepeat;
	}

	bool InitialStyle::getBackgroundSmooth()
	{
		return m_initialStyle.visualData.Read().backgroundSmooth;
	}

	BackgroundSize InitialStyle::getBackgroundSize()
	{
		return m_initialStyle.visualData.Read().backgroundSize;
	}

	sf::Color InitialStyle::getBorderColor()
	{
		return m_initialStyle.visualData.Read().borderColor;
	}

	Length InitialStyle::getBorderRadius()
	{
		return m_initialStyle.visualData.Read().borderRadius;
	}

	float InitialStyle::getBorderWidth()
	{
		return m_initialStyle.layoutData.Read().borderWidth;
	}

	Length InitialStyle::getBottom()
	{
		return m_initialStyle.layoutData.Read().bottom;
	}

	sf::Color InitialStyle::getColor()
	{
		return m_initialStyle.inheritedData.Read().textColor;
	}

	DisplayEnum InitialStyle::getDisplay()
	{
		return m_initialStyle.layoutData.Read().display;
	}

	Length InitialStyle::getFlexBasis()
	{
		return m_initialStyle.layoutData.Read().flexBasis;
	}

	FlexDirectionEnum InitialStyle::getFlexDirection()
	{
		return m_initialStyle.layoutData.Read().flexDirection;
	}

	float InitialStyle::getFlexGrow()
	{
		return m_initialStyle.layoutData.Read().flexGrow;
	}

	float InitialStyle::getFlexShrink()
	{
		return m_initialStyle.layoutData.Read().flexShrink;
	}

	FlexWrapEnum InitialStyle::getFlexWrap()
	{
		return m_initialStyle.layoutData.Read().flexWrap;
	}

	Length InitialStyle::getFontSize()
	{
		return m_initialStyle.inheritedData.Read().fontSize;
	}

	Length InitialStyle::getHeight()
	{
		return m_initialStyle.layoutData.Read().height;
	}

	JustifyEnum InitialStyle::getJustifyContent()
	{
		return m_initialStyle.layoutData.Read().justifyContent;
	}

	Length InitialStyle::getLeft()
	{
		return m_initialStyle.layoutData.Read().left;
	}

	Length InitialStyle::getMarginBottom()
	{
		return m_initialStyle.layoutData.Read().marginBottom;
	}

	Length InitialStyle::getMarginLeft()
	{
		return m_initialStyle.layoutData.Read().marginLeft;
	}

	Length InitialStyle::getMarginRight()
	{
		return m_initialStyle.layoutData.Read().marginRight;
	}

	Length InitialStyle::getMarginTop()
	{
		return m_initialStyle.layoutData.Read().marginTop;
	}

	Length InitialStyle::getMaxHeight()
	{
		return m_initialStyle.layoutData.Read().maxHeight;
	}

	Length InitialStyle::getMaxWidth()
	{
		return m_initialStyle.layoutData.Read().maxWidth;
	}

	Length InitialStyle::getMinHeight()
	{
		return m_initialStyle.layoutData.Read().minHeight;
	}

	Length InitialStyle::getMinWidth()
	{
		return m_initialStyle.layoutData.Read().minWidth;
	}

	float InitialStyle::getOpacity()
	{
		return m_initialStyle.visualData.Read().opacity;
	}

	Length InitialStyle::getPaddingBottom()
	{
		return m_initialStyle.layoutData.Read().paddingBottom;
	}

	Length InitialStyle::getPaddingLeft()
	{
		return m_initialStyle.layoutData.Read().paddingLeft;
	}

	Length InitialStyle::getPaddingRight()
	{
		return m_initialStyle.layoutData.Read().paddingRight;
	}

	Length InitialStyle::getPaddingTop()
	{
		return m_initialStyle.layoutData.Read().paddingTop;
	}

	PositionEnum InitialStyle::getPosition()
	{
		return m_initialStyle.layoutData.Read().position;
	}

	Length InitialStyle::getRight()
	{
		return m_initialStyle.layoutData.Read().right;
	}

	sf::Angle InitialStyle::getRotate()
	{
		return m_initialStyle.transformData.Read().rotate;
	}

	sf::Vector2f InitialStyle::getScale()
	{
		return m_initialStyle.transformData.Read().scale;
	}

	Length InitialStyle::getTop()
	{
		return m_initialStyle.layoutData.Read().top;
	}

	TransformOrigin InitialStyle::getTransformOrigin()
	{
		return m_initialStyle.transformData.Read().transformOrigin;
	}

	TransformTranslate InitialStyle::getTranslate()
	{
		return m_initialStyle.transformData.Read().translate;
	}

	sf::Color InitialStyle::getBackgroundImageTint()
	{
		return m_initialStyle.visualData.Read().backgroundImageTint;
	}

	sf::Font InitialStyle::getTextFont()
	{
		return m_initialStyle.inheritedData.Read().textFont;
	}

	FontStyleEnum InitialStyle::getFontStyle()
	{
		return m_initialStyle.inheritedData.Read().fontStyle;
	}

	TextAlignEnum InitialStyle::getTextAlign()
	{
		return m_initialStyle.inheritedData.Read().textAlign;
	}

	VisibilityEnum InitialStyle::getVisibility()
	{
		return m_initialStyle.inheritedData.Read().visibility;
	}

	Length InitialStyle::getWidth()
	{
		return m_initialStyle.layoutData.Read().width;
	}

	ComputedStyle& InitialStyle::get()
	{
		return m_initialStyle;
	}

	ComputedStyle InitialStyle::acquire()
	{
		return m_initialStyle.acquire();
	}

}