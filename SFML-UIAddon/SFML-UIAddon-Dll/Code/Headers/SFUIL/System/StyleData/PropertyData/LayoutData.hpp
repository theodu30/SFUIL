#pragma once

#include "../../Exports.hpp"
#include "../../Length.hpp"
#include "../PropertyData/StyleEnumList.hpp"

namespace sfui
{
	class SFUIL_API LayoutData
	{
	public:
		Length top;
		Length right;
		Length left;
		Length bottom;

		Length marginTop;
		Length marginRight;
		Length marginLeft;
		Length marginBottom;

		Length paddingTop;
		Length paddingRight;
		Length paddingLeft;
		Length paddingBottom;

		Length height;
		Length width;
		Length minHeight;
		Length minWidth;
		Length maxHeight;
		Length maxWidth;

		Length flexBasis;
		
		float flexGrow = 0.f;
		float flexShrink = 0.f;
		float borderWidth = 0.f;
		
		AlignEnum alignContent = (AlignEnum)0;
		AlignEnum alignItems = (AlignEnum)0;
		AlignEnum alignSelf = (AlignEnum)0;
		DisplayEnum display = (DisplayEnum)0;
		FlexDirectionEnum flexDirection = (FlexDirectionEnum)0;
		FlexWrapEnum flexWrap = (FlexWrapEnum)0;
		JustifyEnum justifyContent = (JustifyEnum)0;
		PositionEnum position = (PositionEnum)0;
	};
}
