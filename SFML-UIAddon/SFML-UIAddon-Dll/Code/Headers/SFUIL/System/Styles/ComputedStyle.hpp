#pragma once

#include "../Exports.hpp"
#include "../StyleData/StyleDataRef.hpp"
#include "../StyleData/PropertyData/InheritedData.hpp"
#include "../StyleData/PropertyData/LayoutData.hpp"
#include "../StyleData/PropertyData/TransformData.hpp"
#include "../StyleData/PropertyData/VisualData.hpp"

namespace sfui
{
	class SFUIL_API ComputedStyle
	{
	public:
		StyleDataRef<InheritedData> inheritedData;
		StyleDataRef<LayoutData> layoutData;
		StyleDataRef<VisualData> visualData;
		StyleDataRef<TransformData> transformData;

		AlignEnum getAlignContent() const;
		AlignEnum getAlignItems() const;
		AlignEnum getAlignSelf() const;
		sf::Color getBackgroundColor() const;
		std::string getTextureKey() const;
		BackgroundPosition getBackgroundPositionX() const;
		BackgroundPosition getBackgroundPositionY() const;
		bool getBackgroundRepeat() const;
		bool getBackgroundSmooth() const;
		BackgroundSize getBackgroundSize() const;
		sf::Color getBorderColor() const;
		Length getBorderRadius() const;
		float getBorderWidth() const;
		Length getBottom() const;
		sf::Color getColor() const;
		DisplayEnum getDisplay() const;
		Length getFlexBasis() const;
		FlexDirectionEnum getFlexDirection() const;
		float getFlexGrow() const;
		float getFlexShrink() const;
		FlexWrapEnum getFlexWrap() const;
		Length getFontSize() const;
		Length getHeight() const;
		JustifyEnum getJustifyContent() const;
		Length getLeft() const;
		Length getMarginBottom() const;
		Length getMarginLeft() const;
		Length getMarginRight() const;
		Length getMarginTop() const;
		Length getMaxHeight() const;
		Length getMaxWidth() const;
		Length getMinHeight() const;
		Length getMinWidth() const;
		float getOpacity() const;
		Length getPaddingBottom() const;
		Length getPaddingLeft() const;
		Length getPaddingRight() const;
		Length getPaddingTop() const;
		PositionEnum getPosition() const;
		Length getRight() const;
		sf::Angle getRotate() const;
		sf::Vector2f getScale() const;
		Length getTop() const;
		TransformOrigin getTransformOrigin() const;
		TransformTranslate getTranslate() const;
		sf::Color getBackgroundImageTint() const;
		sf::Font getTextFont() const;
		FontStyleEnum getFontStyle() const;
		TextAlignEnum getTextAlign() const;
		VisibilityEnum getVisibility() const;
		Length getWidth() const;

		static ComputedStyle create();

		static ComputedStyle create(ComputedStyle& _parentStyle);

		static ComputedStyle createInitial();

		ComputedStyle acquire();

		void release();
	};

	static class SFUIL_API InitialStyle
	{
	private:
		static ComputedStyle m_initialStyle;

		InitialStyle();

	public:
		static AlignEnum getAlignContent();
		static AlignEnum getAlignItems();
		static AlignEnum getAlignSelf();
		static sf::Color getBackgroundColor();
		static std::string getTextureKey();
		static BackgroundPosition getBackgroundPositionX();
		static BackgroundPosition getBackgroundPositionY();
		static bool getBackgroundRepeat();
		static bool getBackgroundSmooth();
		static BackgroundSize getBackgroundSize();
		static sf::Color getBorderColor();
		static Length getBorderRadius();
		static float getBorderWidth();
		static Length getBottom();
		static sf::Color getColor();
		static DisplayEnum getDisplay();
		static Length getFlexBasis();
		static FlexDirectionEnum getFlexDirection();
		static float getFlexGrow();
		static float getFlexShrink();
		static FlexWrapEnum getFlexWrap();
		static Length getFontSize();
		static Length getHeight();
		static JustifyEnum getJustifyContent();
		static Length getLeft();
		static Length getMarginBottom();
		static Length getMarginLeft();
		static Length getMarginRight();
		static Length getMarginTop();
		static Length getMaxHeight();
		static Length getMaxWidth();
		static Length getMinHeight();
		static Length getMinWidth();
		static float getOpacity();
		static Length getPaddingBottom();
		static Length getPaddingLeft();
		static Length getPaddingRight();
		static Length getPaddingTop();
		static PositionEnum getPosition();
		static Length getRight();
		static sf::Angle getRotate();
		static sf::Vector2f getScale();
		static Length getTop();
		static TransformOrigin getTransformOrigin();
		static TransformTranslate getTranslate();
		static sf::Color getBackgroundImageTint();
		static sf::Font getTextFont();
		static FontStyleEnum getFontStyle();
		static TextAlignEnum getTextAlign();
		static VisibilityEnum getVisibility();
		static Length getWidth();

		static ComputedStyle& get();

		static ComputedStyle acquire();
	};
}