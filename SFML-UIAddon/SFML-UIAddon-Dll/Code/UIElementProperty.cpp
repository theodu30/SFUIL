#include "Headers/SFUIL/System/UIElementProperty.hpp"
#include "Headers/SFUIL/UIElement.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

namespace sfui
{
	const float& OpacityProperty::getOpacity() const
	{
		return m_opacity;
	}

	void OpacityProperty::setOpacity(float _opacity)
	{
		// Clamp the value between 0.0f and 1.0f
		m_opacity = UIPropUtils::clampFloat(_opacity, 0.0f, 1.0f);
		m_opacityDirty = true;
	}

	void OpacityProperty::resetOpacity()
	{
		m_opacity = 1.f;
		m_opacityDirty = false;
	}

	float OpacityProperty::resolveFinalOpacity(const UIElement* _element) const
	{
		if (_element->getParent())
		{
			const float parentOpacity = _element->getParent()->getConstProperty<OpacityProperty>().resolveFinalOpacity(_element->getParent());
			return m_opacity * parentOpacity;
		}
		else
		{
			return m_opacity;
		}
	}

	DisplayProperty::Type DisplayProperty::getDisplay() const
	{
		return m_display;
	}

	void DisplayProperty::setDisplay(Type _type)
	{
		m_display = _type;
		m_displayDirty = true;
	}

	void DisplayProperty::resetDisplay()
	{
		m_display = Type::Flex;
		m_displayDirty = false;
	}

	VisibilityProperty::Type VisibilityProperty::getVisibility() const
	{
		return Type();
	}

	void VisibilityProperty::setVisibility(Type _type)
	{
		m_visibility = _type;
		m_visibilityDirty = true;
	}

	void VisibilityProperty::resetVisibility()
	{
		m_visibility = Type::Visible;
		m_visibilityDirty = false;
	}

	PositionProperty::Mode PositionProperty::getMode() const
	{
		return m_mode;
	}

	void PositionProperty::setMode(Mode _mode)
	{
		m_mode = _mode;
		m_modeDirty = true;
	}

	void PositionProperty::resetMode()
	{
		m_mode = Mode::Relative;
		m_modeDirty = false;
	}

	float PositionProperty::Value::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case ValueType::Auto:
			return 0.f;
		case ValueType::Pixels:
			return value;
		case ValueType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const PositionProperty::Value& PositionProperty::getTop() const
	{
		return m_top;
	}

	void PositionProperty::setTop(const Value& _value)
	{
		m_top = _value;
		m_topDirty = true;
	}

	void PositionProperty::setTop(float _value, ValueType _type)
	{
		m_top.value = _value;
		m_top.type = _type;
		m_topDirty = true;
	}

	void PositionProperty::setTop(float _value)
	{
		m_top.value = _value;
		m_topDirty = true;
	}

	void PositionProperty::resetTop()
	{
		m_top = Value();
		m_topDirty = false;
	}

	const PositionProperty::Value& PositionProperty::getRight() const
	{
		return m_right;
	}

	void PositionProperty::setRight(const Value& _value)
	{
		m_right = _value;
		m_rightDirty = true;
	}

	void PositionProperty::setRight(float _value, ValueType _type)
	{
		m_right.value = _value;
		m_right.type = _type;
		m_rightDirty = true;
	}

	void PositionProperty::setRight(float _value)
	{
		m_right.value = _value;
		m_rightDirty = true;
	}

	void PositionProperty::resetRight()
	{
		m_right = Value();
		m_rightDirty = false;
	}

	const PositionProperty::Value& PositionProperty::getBottom() const
	{
		return m_bottom;
	}

	void PositionProperty::setBottom(const Value& _value)
	{
		m_bottom = _value;
		m_bottomDirty = true;
	}

	void PositionProperty::setBottom(float _value, ValueType _type)
	{
		m_bottom.value = _value;
		m_bottom.type = _type;
		m_bottomDirty = true;
	}

	void PositionProperty::setBottom(float _value)
	{
		m_bottom.value = _value;
		m_bottomDirty = true;
	}

	void PositionProperty::resetBottom()
	{
		m_bottom = Value();
		m_bottomDirty = false;
	}

	const PositionProperty::Value& PositionProperty::getLeft() const
	{
		return m_left;
	}

	void PositionProperty::setLeft(const Value& _value)
	{
		m_left = _value;
		m_leftDirty = true;
	}

	void PositionProperty::setLeft(float _value, ValueType _type)
	{
		m_left.value = _value;
		m_left.type = _type;
		m_leftDirty = true;
	}

	void PositionProperty::setLeft(float _value)
	{
		m_left.value = _value;
		m_leftDirty = true;
	}

	void PositionProperty::resetLeft()
	{
		m_left = Value();
		m_leftDirty = false;
	}

	float FlexProperty::Basic::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case BasicType::Auto:
			return 0.f;
		case BasicType::Pixels:
			return value;
		case BasicType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const FlexProperty::Basic& FlexProperty::getFlexBasic() const
	{
		return m_flexBasis;
	}

	void FlexProperty::setFlexBasic(const Basic& _value)
	{
		m_flexBasis = _value;
		m_flexBasisDirty = true;
	}

	void FlexProperty::setFlexBasic(float _value, BasicType _type)
	{
		m_flexBasis.value = _value;
		m_flexBasis.type = _type;
		m_flexBasisDirty = true;
	}

	void FlexProperty::setFlexBasic(float _value)
	{
		m_flexBasis.value = _value;
		m_flexBasisDirty = true;
	}

	void FlexProperty::resetFlexBasic()
	{
		m_flexBasis = Basic();
		m_flexBasisDirty = false;
	}

	const float& FlexProperty::getFlexShrink() const
	{
		return m_flexShrink;
	}

	void FlexProperty::setFlexShrink(float _value)
	{
		m_flexShrink = _value;
		m_flexShrinkDirty = true;
	}

	void FlexProperty::resetFlexShrink()
	{
		m_flexShrink = 1.f;
		m_flexShrinkDirty = false;
	}

	const float& FlexProperty::getFlexGrow() const
	{
		return m_flexGrow;
	}

	void FlexProperty::setFlexGrow(float _value)
	{
		m_flexGrow = _value;
		m_flexGrowDirty = true;
	}

	void FlexProperty::resetFlexGrow()
	{
		m_flexGrow = 1.f;
		m_flexGrowDirty = false;
	}

	FlexProperty::Direction FlexProperty::getFlexDirection() const
	{
		return m_flexDirection;
	}

	void FlexProperty::setFlexDirection(Direction _direction)
	{
		m_flexDirection = _direction;
		m_flexDirectionDirty = true;
	}

	void FlexProperty::resetFlexDirection()
	{
		m_flexDirection = Direction::Column;
		m_flexDirectionDirty = false;
	}

	FlexProperty::Warp FlexProperty::getFlexWrap() const
	{
		return m_flexWrap;
	}

	void FlexProperty::setFlexWrap(Warp _warp)
	{
		m_flexWrap = _warp;
		m_flexWrapDirty = true;
	}

	void FlexProperty::resetFlexWrap()
	{
		m_flexWrap = Warp::NoWrap;
		m_flexWrapDirty = false;
	}

	AlignProperty::AlignItems AlignProperty::getAlignItems() const
	{
		return m_alignItems;
	}

	void AlignProperty::setAlignItems(AlignItems _alignItems)
	{
		m_alignItems = _alignItems;
		m_alignItemsDirty = true;
	}

	void AlignProperty::resetAlignItems()
	{
		m_alignItems = AlignItems::Stretch;
		m_alignItemsDirty = false;
	}

	AlignProperty::JustifyContent AlignProperty::getJustifyContent() const
	{
		return m_justifyContent;
	}

	void AlignProperty::setJustifyContent(JustifyContent _justifyContent)
	{
		m_justifyContent = _justifyContent;
		m_justifyContentDirty = true;
	}

	void AlignProperty::resetJustifyContent()
	{
		m_justifyContent = JustifyContent::FlexStart;
		m_justifyContentDirty = false;
	}

	AlignProperty::AlignSelf AlignProperty::getAlignSelf() const
	{
		return m_alignSelf;
	}

	void AlignProperty::setAlignSelf(AlignSelf _alignSelf)
	{
		m_alignSelf = _alignSelf;
		m_alignSelfDirty = true;
	}

	void AlignProperty::resetAlignSelf()
	{
		m_alignSelf = AlignSelf::Auto;
		m_alignSelfDirty = false;
	}

	AlignProperty::AlignContent AlignProperty::getAlignContent() const
	{
		return m_alignContent;
	}

	void AlignProperty::setAlignContent(AlignContent _alignContent)
	{
		m_alignContent = _alignContent;
		m_alignContentDirty = true;
	}

	void AlignProperty::resetAlignContent()
	{
		m_alignContent = AlignContent::FlexStart;
		m_alignContentDirty = false;
	}

	float SizeProperty::SizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case SizeType::Auto:
			return 0.f;
		case SizeType::Pixels:
			return value;
		case SizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SizeProperty::Size& SizeProperty::getSize() const
	{
		return m_size;
	}

	void SizeProperty::setSize(const Size& _size)
	{
		m_size = _size;
		m_size.widthDirty = true;
		m_size.heightDirty = true;
	}

	void SizeProperty::setWidth(float _value, SizeType _type)
	{
		m_size.width.value = _value;
		m_size.width.type = _type;
		m_size.widthDirty = true;
	}

	void SizeProperty::setWidth(float _value)
	{
		m_size.width.value = _value;
		m_size.widthDirty = true;
	}

	void SizeProperty::setHeight(float _value, SizeType _type)
	{
		m_size.height.value = _value;
		m_size.height.type = _type;
		m_size.heightDirty = true;
	}

	void SizeProperty::setHeight(float _value)
	{
		m_size.height.value = _value;
		m_size.heightDirty = true;
	}

	void SizeProperty::resetSize()
	{
		m_size = Size();
		m_size.widthDirty = false;
		m_size.heightDirty = false;
	}

	void SizeProperty::resetWidth()
	{
		m_size.width = SizeValue();
		m_size.widthDirty = false;
	}

	void SizeProperty::resetHeight()
	{
		m_size.height = SizeValue();
		m_size.heightDirty = false;
	}

	float SizeProperty::MinSizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MinSizeType::Auto:
			return 0.f;
		case MinSizeType::Pixels:
			return value;
		case MinSizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SizeProperty::MinSize& SizeProperty::getMinSize() const
	{
		return m_minSize;
	}

	void SizeProperty::setMinSize(const MinSize& _minSize)
	{
		m_minSize = _minSize;
		m_minSize.widthDirty = true;
		m_minSize.heightDirty = true;
	}

	void SizeProperty::setMinWidth(float _value, MinSizeType _type)
	{
		m_minSize.width.value = _value;
		m_minSize.width.type = _type;
		m_minSize.widthDirty = true;
	}

	void SizeProperty::setMinWidth(float _value)
	{
		m_minSize.width.value = _value;
		m_minSize.widthDirty = true;
	}

	void SizeProperty::setMinHeight(float _value, MinSizeType _type)
	{
		m_minSize.height.value = _value;
		m_minSize.height.type = _type;
		m_minSize.heightDirty = true;
	}

	void SizeProperty::setMinHeight(float _value)
	{
		m_minSize.height.value = _value;
		m_minSize.heightDirty = true;
	}

	void SizeProperty::resetMinSize()
	{
		m_minSize = MinSize();
		m_minSize.widthDirty = false;
		m_minSize.heightDirty = false;
	}

	void SizeProperty::resetMinWidth()
	{
		m_minSize.width = MinSizeValue();
		m_minSize.widthDirty = false;
	}

	void SizeProperty::resetMinHeight()
	{
		m_minSize.height = MinSizeValue();
		m_minSize.heightDirty = false;
	}

	float SizeProperty::MaxSizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MaxSizeType::None:
			return _relativeTo;
		case MaxSizeType::Pixels:
			return value;
		case MaxSizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return _relativeTo;
		}
	}

	const SizeProperty::MaxSize& SizeProperty::getMaxSize() const
	{
		return m_maxSize;
	}

	void SizeProperty::setMaxSize(const MaxSize& _maxSize)
	{
		m_maxSize = _maxSize;
		m_maxSize.widthDirty = true;
		m_maxSize.heightDirty = true;
	}

	void SizeProperty::setMaxWidth(float _value, MaxSizeType _type)
	{
		m_maxSize.width.value = _value;
		m_maxSize.width.type = _type;
		m_maxSize.widthDirty = true;
	}

	void SizeProperty::setMaxWidth(float _value)
	{
		m_maxSize.width.value = _value;
		m_maxSize.widthDirty = true;
	}

	void SizeProperty::setMaxHeight(float _value, MaxSizeType _type)
	{
		m_maxSize.height.value = _value;
		m_maxSize.height.type = _type;
		m_maxSize.heightDirty = true;
	}

	void SizeProperty::setMaxHeight(float _value)
	{
		m_maxSize.height.value = _value;
		m_maxSize.heightDirty = true;
	}

	void SizeProperty::resetMaxSize()
	{
		m_maxSize = MaxSize();
		m_maxSize.widthDirty = false;
		m_maxSize.heightDirty = false;
	}

	void SizeProperty::resetMaxWidth()
	{
		m_maxSize.width = MaxSizeValue();
		m_maxSize.widthDirty = false;
	}

	void SizeProperty::resetMaxHeight()
	{
		m_maxSize.height = MaxSizeValue();
		m_maxSize.heightDirty = false;
	}

	float SpacingProperty::MarginValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case MarginType::Auto:
			return 0.f;
		case MarginType::Pixels:
			return value;
		case MarginType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginTop() const
	{
		return m_marginTop;
	}

	void SpacingProperty::setMarginTop(const MarginValue& _value)
	{
		m_marginTop = _value;
		m_marginTopDirty = true;
	}

	void SpacingProperty::setMarginTop(float _value, MarginType _type)
	{
		m_marginTop.value = _value;
		m_marginTop.type = _type;
		m_marginTopDirty = true;
	}

	void SpacingProperty::setMarginTop(float _value)
	{
		m_marginTop.value = _value;
		m_marginTopDirty = true;
	}

	void SpacingProperty::resetMarginTop()
	{
		m_marginTop = MarginValue();
		m_marginTopDirty = false;
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginRight() const
	{
		return m_marginRight;
	}

	void SpacingProperty::setMarginRight(const MarginValue& _value)
	{
		m_marginRight = _value;
		m_marginRightDirty = true;
	}

	void SpacingProperty::setMarginRight(float _value, MarginType _type)
	{
		m_marginRight.value = _value;
		m_marginRight.type = _type;
		m_marginRightDirty = true;
	}

	void SpacingProperty::setMarginRight(float _value)
	{
		m_marginRight.value = _value;
		m_marginRightDirty = true;
	}

	void SpacingProperty::resetMarginRight()
	{
		m_marginRight = MarginValue();
		m_marginRightDirty = false;
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginBottom() const
	{
		return m_marginBottom;
	}

	void SpacingProperty::setMarginBottom(const MarginValue& _value)
	{
		m_marginBottom = _value;
		m_marginBottomDirty = true;
	}

	void SpacingProperty::setMarginBottom(float _value, MarginType _type)
	{
		m_marginBottom.value = _value;
		m_marginBottom.type = _type;
		m_marginBottomDirty = true;
	}

	void SpacingProperty::setMarginBottom(float _value)
	{
		m_marginBottom.value = _value;
		m_marginBottomDirty = true;
	}

	void SpacingProperty::resetMarginBottom()
	{
		m_marginBottom = MarginValue();
		m_marginBottomDirty = false;
	}

	const SpacingProperty::MarginValue& SpacingProperty::getMarginLeft() const
	{
		return m_marginLeft;
	}

	void SpacingProperty::setMarginLeft(const MarginValue& _value)
	{
		m_marginLeft = _value;
		m_marginLeftDirty = true;
	}

	void SpacingProperty::setMarginLeft(float _value, MarginType _type)
	{
		m_marginLeft.value = _value;
		m_marginLeft.type = _type;
		m_marginLeftDirty = true;
	}

	void SpacingProperty::setMarginLeft(float _value)
	{
		m_marginLeft.value = _value;
		m_marginLeftDirty = true;
	}

	void SpacingProperty::resetMarginLeft()
	{
		m_marginLeft = MarginValue();
		m_marginLeftDirty = false;
	}

	float SpacingProperty::PaddingValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case PaddingType::Auto:
			return 0.f;
		case PaddingType::Pixels:
			return value;
		case PaddingType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingTop() const
	{
		return m_paddingTop;
	}

	void SpacingProperty::setPaddingTop(const PaddingValue& _value)
	{
		m_paddingTop = _value;
		m_paddingTopDirty = false;
	}

	void SpacingProperty::setPaddingTop(float _value, PaddingType _type)
	{
		m_paddingTop.value = _value;
		m_paddingTop.type = _type;
		m_paddingTopDirty = false;
	}

	void SpacingProperty::setPaddingTop(float _value)
	{
		m_paddingTop.value = _value;
		m_paddingTopDirty = false;
	}

	void SpacingProperty::resetPaddingTop()
	{
		m_paddingTop = PaddingValue();
		m_paddingTopDirty = false;
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingRight() const
	{
		return m_paddingRight;
	}

	void SpacingProperty::setPaddingRight(const PaddingValue& _value)
	{
		m_paddingRight = _value;
		m_paddingRightDirty = false;
	}

	void SpacingProperty::setPaddingRight(float _value, PaddingType _type)
	{
		m_paddingRight.value = _value;
		m_paddingRight.type = _type;
		m_paddingRightDirty = false;
	}

	void SpacingProperty::setPaddingRight(float _value)
	{
		m_paddingRight.value = _value;
		m_paddingRightDirty = false;
	}

	void SpacingProperty::resetPaddingRight()
	{
		m_paddingRight = PaddingValue();
		m_paddingRightDirty = false;
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingBottom() const
	{
		return m_paddingBottom;
	}

	void SpacingProperty::setPaddingBottom(const PaddingValue& _value)
	{
		m_paddingBottom = _value;
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::setPaddingBottom(float _value, PaddingType _type)
	{
		m_paddingBottom.value = _value;
		m_paddingBottom.type = _type;
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::setPaddingBottom(float _value)
	{
		m_paddingBottom.value = _value;
		m_paddingBottomDirty = false;
	}

	void SpacingProperty::resetPaddingBottom()
	{
		m_paddingBottom = PaddingValue();
		m_paddingBottomDirty = false;
	}

	const SpacingProperty::PaddingValue& SpacingProperty::getPaddingLeft() const
	{
		return m_paddingLeft;
	}

	void SpacingProperty::setPaddingLeft(const PaddingValue& _value)
	{
		m_paddingLeft = _value;
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::setPaddingLeft(float _value, PaddingType _type)
	{
		m_paddingLeft.value = _value;
		m_paddingLeft.type = _type;
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::setPaddingLeft(float _value)
	{
		m_paddingLeft.value = _value;
		m_paddingLeftDirty = false;
	}

	void SpacingProperty::resetPaddingLeft()
	{
		m_paddingLeft = PaddingValue();
		m_paddingLeftDirty = false;
	}

	const sf::Color& BackgroundProperty::getColor() const
	{
		return m_color;
	}

	void BackgroundProperty::setColor(const sf::Color& _color)
	{
		m_color = _color;
		m_colorDirty = true;
	}

	void BackgroundProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
		m_color.a = _a;
		m_colorDirty = true;
	}

	void BackgroundProperty::resetColor()
	{
		m_color = sf::Color::Transparent;
		m_colorDirty = false;
	}

	const sf::Color& BorderProperty::getColor() const
	{
		return m_color;
	}

	void BorderProperty::setColor(const sf::Color& _color)
	{
		m_color = _color;
		m_colorDirty = true;
	}

	void BorderProperty::setColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_color.r = _r;
		m_color.g = _g;
		m_color.b = _b;
		m_color.a = _a;
		m_colorDirty = true;
	}

	void BorderProperty::resetColor()
	{
		m_color = sf::Color::Black;
		m_colorDirty = false;
	}

	const float& BorderProperty::getWidth() const
	{
		return m_width;
	}

	void BorderProperty::setWidth(float _width)
	{
		m_width = _width;
		m_widthDirty = true;
	}

	void BorderProperty::resetWidth()
	{
		m_width = 0.f;
		m_widthDirty = false;
	}

	const float& BorderProperty::getRadius() const
	{
		return m_radius;
	}

	void BorderProperty::setRadius(float _radius)
	{
		m_radius = _radius;
		m_radiusDirty = true;
	}

	void BorderProperty::resetRadius()
	{
		m_radius = 0.f;
		m_radiusDirty = false;
	}

	float TransformProperty::OriginValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case OriginType::Pixels:
			return value;
		case OriginType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const TransformProperty::Origin& TransformProperty::getOrigin() const
	{
		return m_origin;
	}

	void TransformProperty::setOrigin(const Origin& _origin)
	{
		m_origin = _origin;
		m_origin.xDirty = true;
		m_origin.yDirty = true;
	}

	void TransformProperty::setOriginX(float _value, OriginType _type)
	{
		m_origin.x.value = _value;
		m_origin.x.type = _type;
		m_origin.xDirty = true;
	}

	void TransformProperty::setOriginX(float _value)
	{
		m_origin.x.value = _value;
		m_origin.xDirty = true;
	}

	void TransformProperty::setOriginY(float _value, OriginType _type)
	{
		m_origin.y.value = _value;
		m_origin.y.type = _type;
		m_origin.yDirty = true;
	}

	void TransformProperty::setOriginY(float _value)
	{
		m_origin.y.value = _value;
		m_origin.yDirty = true;
	}

	void TransformProperty::resetOrigin()
	{
		m_origin = Origin();
		m_origin.xDirty = false;
		m_origin.yDirty = false;
	}

	void TransformProperty::resetOriginX()
	{
		m_origin.x = OriginValue();
		m_origin.xDirty = false;
	}

	void TransformProperty::resetOriginY()
	{
		m_origin.y = OriginValue();
		m_origin.yDirty = false;
	}

	float TransformProperty::TranslateValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case TranslateType::Pixels:
			return value;
		case TranslateType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const TransformProperty::Translate& TransformProperty::getTranslate() const
	{
		return m_translate;
	}

	void TransformProperty::setTranslate(const Translate& _translate)
	{
		m_translate = _translate;
		m_translate.xDirty = true;
		m_translate.yDirty = true;
	}

	void TransformProperty::setTranslateX(float _value, TranslateType _type)
	{
		m_translate.x.value = _value;
		m_translate.x.type = _type;
		m_translate.xDirty = true;
	}

	void TransformProperty::setTranslateX(float _value)
	{
		m_translate.x.value = _value;
		m_translate.xDirty = true;
	}

	void TransformProperty::setTranslateY(float _value, TranslateType _type)
	{
		m_translate.y.value = _value;
		m_translate.y.type = _type;
		m_translate.yDirty = true;
	}

	void TransformProperty::setTranslateY(float _value)
	{
		m_translate.y.value = _value;
		m_translate.yDirty = true;
	}

	void TransformProperty::resetTranslate()
	{
		m_translate = Translate();
		m_translate.xDirty = false;
		m_translate.yDirty = false;
	}

	void TransformProperty::resetTranslateX()
	{
		m_translate.x = TranslateValue();
		m_translate.xDirty = false;
	}

	void TransformProperty::resetTranslateY()
	{
		m_translate.y = TranslateValue();
		m_translate.yDirty = false;
	}

	const TransformProperty::Scale& TransformProperty::getScale() const
	{
		return m_scale;
	}

	void TransformProperty::setScale(const Scale& _scale)
	{
		m_scale = _scale;
		m_scale.xDirty = true;
		m_scale.yDirty = true;
	}

	void TransformProperty::setScaleX(float _value)
	{
		m_scale.x = _value;
		m_scale.xDirty = true;
	}

	void TransformProperty::setScaleY(float _value)
	{
		m_scale.y = _value;
		m_scale.yDirty = true;
	}

	void TransformProperty::resetScale()
	{
		m_scale = Scale();
		m_scale.xDirty = false;
		m_scale.yDirty = false;
	}

	void TransformProperty::resetScaleX()
	{
		m_scale.x = 1.f;
	}

	void TransformProperty::resetScaleY()
	{
		m_scale.y = 1.f;
	}

	float TransformProperty::Rotate::resolveToDegrees() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return value;
		case RotateType::Radians:
			return value * (180.f / static_cast<float>(M_PI));
		default:
			return 0.f;
		}
	}

	float TransformProperty::Rotate::resolveToRadians() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return value * (static_cast<float>(M_PI) / 180.f);
		case RotateType::Radians:
			return value;
		default:
			return 0.f;
		}
	}

	sf::Angle TransformProperty::Rotate::resolveToSfAngle() const
	{
		switch (type)
		{
		case RotateType::Degrees:
			return sf::degrees(value);
		case RotateType::Radians:
			return sf::radians(value);
		default:
			return sf::degrees(0.f);
		}
	}

	const TransformProperty::Rotate& TransformProperty::getRotate() const
	{
		return m_rotate;
	}

	void TransformProperty::setRotate(const Rotate& _rotate)
	{
		m_rotate = _rotate;
		m_rotateDirty = true;
	}

	void TransformProperty::setRotate(float _value, RotateType _type)
	{
		m_rotate.value = _value;
		m_rotate.type = _type;
		m_rotateDirty = true;
	}

	void TransformProperty::setRotate(float _value)
	{
		m_rotate.value = _value;
		m_rotateDirty = true;
	}

	void TransformProperty::resetRotate()
	{
		m_rotate = Rotate();
		m_rotateDirty = false;
	}

	void UIPropUtils::normalizeAngle(TransformProperty& _prop)
	{
		_prop.setRotate(normalizedAngle(_prop.getRotate()));
	}

	TransformProperty::Rotate UIPropUtils::normalizedAngle(const TransformProperty::Rotate& _rotate)
	{
		switch (_rotate.type)
		{
		case TransformProperty::RotateType::Degrees:
		{
			float degrees = std::fmod(_rotate.value, 360.f);
			if (degrees > 180.f)
				degrees -= 360.f;
			else if (degrees < -180.f)
				degrees += 360.f;
			return TransformProperty::Rotate{ degrees, TransformProperty::RotateType::Degrees };
		}
		case TransformProperty::RotateType::Radians:
		{
			const float twoPi = static_cast<float>(2 * M_PI);
			float radians = std::fmod(_rotate.value, twoPi);
			if (radians > static_cast<float>(M_PI))
				radians -= twoPi;
			else if (radians < -static_cast<float>(M_PI))
				radians += twoPi;
			return TransformProperty::Rotate{ radians, TransformProperty::RotateType::Radians };
		}
		default:
			return _rotate;
		}
	}

	bool UIPropUtils::isFlexDirectionRowType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::Row ||
			_flex.getFlexDirection() == FlexProperty::Direction::RowReverse;
	}

	bool UIPropUtils::isFlexDirectionColumnType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::Column ||
			_flex.getFlexDirection() == FlexProperty::Direction::ColumnReverse;
	}

	bool UIPropUtils::isFlexDirectionReverseType(const FlexProperty& _flex)
	{
		return _flex.getFlexDirection() == FlexProperty::Direction::RowReverse ||
			_flex.getFlexDirection() == FlexProperty::Direction::ColumnReverse;
	}

	bool UIPropUtils::isPositionAbsolute(const PositionProperty& _position)
	{
		return _position.getMode() == PositionProperty::Mode::Absolute;
	}

	bool UIPropUtils::isPositionRelative(const PositionProperty& _position)
	{
		return _position.getMode() == PositionProperty::Mode::Relative;
	}

	float UIPropUtils::clampFloat(float _value, float _min, float _max)
	{
		if (_value < _min)
			return _min;
		if (_value > _max)
			return _max;
		return _value;
	}

	unsigned int UIPropUtils::clampUnsignedInt(unsigned int _value, unsigned int _min, unsigned int _max)
	{
		if (_value < _min)
			return _min;
		if (_value > _max)
			return _max;
		return _value;
	}

	float UIPropUtils::calculateJustifyContentOffset(const AlignProperty& _justifyContent, size_t _siblingIndex, size_t _siblingCount, float _elementSize, float _parentSize)
	{
		switch (_justifyContent.getJustifyContent())
		{
		case AlignProperty::JustifyContent::FlexStart:
			return static_cast<float>(_siblingIndex) * _elementSize;
		case AlignProperty::JustifyContent::FlexEnd:
			return _parentSize - (_elementSize * static_cast<float>(_siblingCount - _siblingIndex));
		case AlignProperty::JustifyContent::Center:
			return ((_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / 2.f) + (static_cast<float>(_siblingIndex) * _elementSize);
		case AlignProperty::JustifyContent::SpaceBetween:
			if (_siblingCount > 1)
			{
				float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount - 1);
				return (static_cast<float>(_siblingIndex) * (_elementSize + space));
			}
			else
			{
				return 0.f;
			}
		case AlignProperty::JustifyContent::SpaceAround:
		{
			float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount);
			return (space / 2.f) + (static_cast<float>(_siblingIndex) * (_elementSize + space));
		}
		case AlignProperty::JustifyContent::SpaceEvenly:
		{
			float space = (_parentSize - (_elementSize * static_cast<float>(_siblingCount))) / static_cast<float>(_siblingCount + 1);
			return space + (static_cast<float>(_siblingIndex) * (_elementSize + space));
		}
		default:
			return 0.f;
		}
	}

	float UIPropUtils::calculateAlignItemsOffset(const AlignProperty& _alignItems, float _elementSize, float _parentSize)
	{
		switch (_alignItems.getAlignItems())
		{
		case AlignProperty::AlignItems::FlexStart:
			return 0.f;
		case AlignProperty::AlignItems::FlexEnd:
			return _parentSize - _elementSize;
		case AlignProperty::AlignItems::Center:
			return (_parentSize - _elementSize) / 2.f;
		case AlignProperty::AlignItems::Stretch:
			return 0.f;
		default:
			return 0.f;
		}
	}

	void UIPropUtils::applyWorldTransform(sf::Transformable& _transformable, const sf::Transform& _transform)
	{
		_transformable.setPosition(_transform.transformPoint({ 0.f, 0.f }));

		const float* m = _transform.getMatrix();
		float angleRad = std::atan2(m[1], m[0]);
		_transformable.setRotation(sf::radians(angleRad));

		float scaleX = std::sqrt(m[0] * m[0] + m[1] * m[1]);
		float scaleY = std::sqrt(m[4] * m[4] + m[5] * m[5]);
		_transformable.setScale({ scaleX, scaleY });
	}

	ImageProperty::Repeat ImageProperty::getRepeat() const
	{
		return m_repeat;
	}

	void ImageProperty::setRepeat(Repeat _repeat)
	{
		m_repeat = _repeat;
		m_repeatDirty = true;
	}

	void ImageProperty::resetRepeat()
	{
		m_repeat = Repeat::NoRepeat;
		m_repeatDirty = false;
	}

	ImageProperty::Smooth ImageProperty::getSmooth() const
	{
		return m_smooth;
	}

	void ImageProperty::setSmooth(Smooth _smooth)
	{
		m_smooth = _smooth;
		m_smoothDirty = true;
	}

	void ImageProperty::resetSmooth()
	{
		m_smooth = Smooth::Pixelated;

	}

	const char* ImageProperty::getImagePath() const
	{
		return m_imagePath;
	}

	void ImageProperty::setImagePath(const char* _imagePath)
	{
		m_imagePath = _imagePath;
		m_imagePathDirty = true;
	}

	void ImageProperty::resetImagePath()
	{
		m_imagePath = nullptr;
		m_imagePathDirty = false;
	}

	const sf::Color& ImageProperty::getTintColor() const
	{
		return m_tintColor;
	}

	void ImageProperty::setTintColor(const sf::Color& _color)
	{
		m_tintColor = _color;
		m_tintColorDirty = true;
	}

	void ImageProperty::setTintColor(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a)
	{
		m_tintColor.r = _r;
		m_tintColor.g = _g;
		m_tintColor.b = _b;
		m_tintColor.a = _a;
		m_tintColorDirty = true;
	}

	void ImageProperty::resetTintColor()
	{
		m_tintColor = sf::Color::White;
		m_tintColorDirty = false;
	}

	const sf::Image& ImageProperty::getImage() const
	{
		return m_image;
	}

	bool ImageProperty::loadImage()
	{
		if (m_imagePath != nullptr)
		{
			return m_image.loadFromFile(m_imagePath);
		}
		return false;
	}

	float ImageProperty::SizeValue::resolveToPixels(float _relativeTo) const
	{
		switch (type)
		{
		case SizeType::Pixels:
			return value;
		case SizeType::Percentage:
			return (value / 100.f) * _relativeTo;
		default:
			return 0.f;
		}
	}

	const ImageProperty::Size& ImageProperty::getSize() const
	{
		return m_size;
	}

	void ImageProperty::setSize(const Size& _size)
	{
		m_size = _size;
		m_size.widthDirty = true;
		m_size.heightDirty = true;
	}

	void ImageProperty::setWidth(float _value, SizeType _type)
	{
		m_size.width.value = _value;
		m_size.width.type = _type;
		m_size.widthDirty = true;
	}

	void ImageProperty::setWidth(float _value)
	{
		m_size.width.value = _value;
		m_size.widthDirty = true;
	}

	void ImageProperty::setHeight(float _value, SizeType _type)
	{
		m_size.height.value = _value;
		m_size.height.type = _type;
		m_size.heightDirty = true;
	}

	void ImageProperty::setHeight(float _value)
	{
		m_size.height.value = _value;
		m_size.heightDirty = true;
	}

	void ImageProperty::resetSize()
	{
		m_size = Size();
		m_size.widthDirty = false;
		m_size.heightDirty = false;
	}

	void ImageProperty::resetWidth()
	{
		m_size.width = SizeValue();
		m_size.widthDirty = false;
	}

	void ImageProperty::resetHeight()
	{
		m_size.height = SizeValue();
		m_size.heightDirty = false;
	}

	float ImageProperty::PositionX::resolveToPixels(float _relativeSize, float _relativeTo) const
	{
		if (position == PositionXPositionType::Center)
		{
			return (_relativeTo / 2.f) - (_relativeSize / 2.f);
		}
		else if (position == PositionXPositionType::Right)
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return _relativeTo - _relativeSize - offsetValue;
			case PositionOffsetType::Percentage:
				return _relativeTo - _relativeSize - ((offsetValue / 100.f) * _relativeTo);
			default:
				return 0.f;
			}
		}
		else // Left
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return offsetValue;
			case PositionOffsetType::Percentage:
				return (offsetValue / 100.f) * _relativeTo;
			default:
				return 0.f;
			}
		}
	}

	float ImageProperty::PositionY::resolveToPixels(float _relativeSize, float _relativeTo) const
	{
		if (position == PositionYPositionType::Center)
		{
			return (_relativeTo / 2.f) - (_relativeSize / 2.f);
		}
		else if (position == PositionYPositionType::Bottom)
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return _relativeTo - _relativeSize - offsetValue;
			case PositionOffsetType::Percentage:
				return _relativeTo - _relativeSize - ((offsetValue / 100.f) * _relativeTo);
			default:
				return 0.f;
			}
		}
		else // Top
		{
			switch (offsetType)
			{
			case PositionOffsetType::Pixels:
				return offsetValue;
			case PositionOffsetType::Percentage:
				return (offsetValue / 100.f) * _relativeTo;
			default:
				return 0.f;
			}
		}
	}

	const ImageProperty::PositionX& ImageProperty::getPositionX() const
	{
		return m_positionX;
	}

	void ImageProperty::setPositionX(const PositionX& _positionX)
	{
		m_positionX = _positionX;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(PositionXPositionType _position, float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionX.position = _position;
		m_positionX.offsetValue = _offsetValue;
		m_positionX.offsetType = _offsetType;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(PositionXPositionType _position, float _offsetValue)
	{
		m_positionX.position = _position;
		m_positionX.offsetValue = _offsetValue;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionX.offsetValue = _offsetValue;
		m_positionX.offsetType = _offsetType;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(float _offsetValue)
	{
		m_positionX.offsetValue = _offsetValue;
		m_positionXDirty = true;
	}

	void ImageProperty::setPositionX(PositionXPositionType _position)
	{
		m_positionX.position = _position;
		m_positionXDirty = true;
	}

	void ImageProperty::resetPositionX()
	{
		m_positionX = PositionX();
		m_positionXDirty = false;
	}

	const ImageProperty::PositionY& ImageProperty::getPositionY() const
	{
		return m_positionY;
	}

	void ImageProperty::setPositionY(const PositionY& _positionY)
	{
		m_positionY = _positionY;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(PositionYPositionType _position, float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionY.position = _position;
		m_positionY.offsetValue = _offsetValue;
		m_positionY.offsetType = _offsetType;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(PositionYPositionType _position, float _offsetValue)
	{
		m_positionY.position = _position;
		m_positionY.offsetValue = _offsetValue;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(float _offsetValue, PositionOffsetType _offsetType)
	{
		m_positionY.offsetValue = _offsetValue;
		m_positionY.offsetType = _offsetType;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(float _offsetValue)
	{
		m_positionY.offsetValue = _offsetValue;
		m_positionYDirty = true;
	}

	void ImageProperty::setPositionY(PositionYPositionType _position)
	{
		m_positionY.position = _position;
		m_positionYDirty = true;
	}

	void ImageProperty::resetPositionY()
	{
		m_positionY = PositionY();
		m_positionYDirty = false;
	}

	ImageProperty::ScaleMode ImageProperty::getScaleMode() const
	{
		return m_scaleMode;
	}

	void ImageProperty::setScaleMode(ScaleMode _mode)
	{
		m_scaleMode = _mode;
		m_scaleModeDirty = true;
	}

	void ImageProperty::resetScaleMode()
	{
		m_scaleMode = ScaleMode::StretchToFill;
		m_scaleModeDirty = false;
	}

	const sf::Vector2f& TransformProperty::getCalculatedOriginPixels() const
	{
		return m_calculatedOriginPixels;
	}

	void TransformProperty::setCalculatedOriginPixels(const sf::Vector2f& _pixels)
	{
		m_calculatedOriginPixels = _pixels;
	}

	void TransformProperty::setCalculatedOriginPixels(float _xPixels, float _yPixels)
	{
		m_calculatedOriginPixels.x = _xPixels;
		m_calculatedOriginPixels.y = _yPixels;
	}

	const sf::Vector2f& TransformProperty::getCalculatedTranslatePixels() const
	{
		return m_calculatedTranslatePixels;
	}

	void TransformProperty::setCalculatedTranslatePixels(const sf::Vector2f& _pixels)
	{
		m_calculatedTranslatePixels = _pixels;
	}

	void TransformProperty::setCalculatedTranslatePixels(float _xPixels, float _yPixels)
	{
		m_calculatedTranslatePixels.x = _xPixels;
		m_calculatedTranslatePixels.y = _yPixels;
	}

	const sf::Vector2f& TransformProperty::getCalculatedScale() const
	{
		return m_calculatedScale;
	}

	void TransformProperty::setCalculatedScale(const sf::Vector2f& _scale)
	{
		m_calculatedScale = _scale;
	}

	void TransformProperty::setCalculatedScale(float _xScale, float _yScale)
	{
		m_calculatedScale.x = _xScale;
		m_calculatedScale.y = _yScale;
	}

	const sf::Angle& TransformProperty::getCalculatedRotateAngle() const
	{
		return m_calculatedRotateAngle;
	}

	void TransformProperty::setCalculatedRotateAngle(const sf::Angle& _angle)
	{
		m_calculatedRotateAngle = _angle;
	}

	sf::Transform TransformProperty::getLocalTransform() const
	{
		sf::Transform t;

		t.translate(m_calculatedTranslatePixels);
		t.translate(m_calculatedOriginPixels);
		t.rotate(m_calculatedRotateAngle);
		t.scale(m_calculatedScale);
		t.translate(-m_calculatedOriginPixels);

		return t;
	}

	sf::Transform TransformProperty::getWorldTransform(const UIElement* _element) const
	{
		sf::Transform local = getLocalTransform();

		if (_element->getParent())
		{
			local = _element->getParent()->getConstProperty<TransformProperty>().getWorldTransform(_element->getParent()) * local;
		}

		return local;
	}

	sf::Vector2f TransformProperty::Scale::toVector2f() const
	{
		return sf::Vector2f(x, y);
	}

	sf::Vector2f TransformProperty::Translate::toVector2f(float _relativeToX, float _relativeToY) const
	{
		return sf::Vector2f(
			x.resolveToPixels(_relativeToX),
			y.resolveToPixels(_relativeToY)
		);
	}

	sf::Vector2f TransformProperty::Origin::toVector2f(float _relativeToX, float _relativeToY) const
	{
		return sf::Vector2f(
			x.resolveToPixels(_relativeToX),
			y.resolveToPixels(_relativeToY)
		);
	}

}
