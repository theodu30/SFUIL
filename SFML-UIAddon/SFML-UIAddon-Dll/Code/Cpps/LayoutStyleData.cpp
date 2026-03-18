#include "../Headers/SFUIL/System/Layout/LayoutStyleData.hpp"
#include "../Headers/SFUIL/System/Layout/LayoutDefaults.hpp"
#include <cmath>

namespace sfui
{
	LayoutStyleData LayoutStyleData::Default = LayoutStyleData();

	LayoutStyleData::LayoutStyleData()
	{
		direction = LayoutDirection::Inherit;
		flexDirection = LayoutFlexDirection::Column;
		justifyContent = LayoutJustify::FlexStart;
		alignContent = LayoutAlign::Auto;
		alignItems = LayoutAlign::Stretch;
		alignSelf = LayoutAlign::Auto;
		positionType = LayoutPositionType::Relative;
		flexWrap = LayoutWrap::NoWrap;
		display = LayoutDisplay::Flex;
		flexGrow = NAN;
		flexShrink = NAN;
		border = LayoutDefaults::EdgeValuesUnit;
		position = LayoutDefaults::EdgeValuesUnit;
		margin = LayoutDefaults::EdgeValuesUnit;
		padding = LayoutDefaults::EdgeValuesUnit;
		dimensions = LayoutDefaults::DimensionValuesAutoUnit;
		minDimensions = LayoutDefaults::DimensionValuesUnit;
	}

}