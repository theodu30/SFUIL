#pragma once

#include "LayoutValue.hpp"
#include "LayoutEnums.hpp"
#include "../Datas/FixedBuffer.hpp"

namespace sfui
{

	class LayoutStyleData
	{
	private:
		LayoutStyleData();

	public:
		static LayoutStyleData Default;

		LayoutDirection direction;
		LayoutFlexDirection flexDirection;
		LayoutJustify justifyContent;
		LayoutAlign alignContent;
		LayoutAlign alignItems;
		LayoutAlign alignSelf;
		LayoutPositionType positionType;
		LayoutWrap flexWrap;
		LayoutDisplay display;
		float flexGrow;
		float flexShrink;
		LayoutValue flexBasis;
		FixedBuffer<LayoutValue, 9> border;
		FixedBuffer<LayoutValue, 9> position;
		FixedBuffer<LayoutValue, 9> margin;
		FixedBuffer<LayoutValue, 9> padding;
		FixedBuffer<LayoutValue, 2> maxDimensions;
		FixedBuffer<LayoutValue, 2> minDimensions;
		FixedBuffer<LayoutValue, 2> dimensions;
	};
}