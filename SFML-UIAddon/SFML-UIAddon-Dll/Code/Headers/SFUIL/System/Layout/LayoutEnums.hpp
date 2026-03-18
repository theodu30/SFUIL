#pragma once

namespace sfui
{
	enum class LayoutDirection : char
	{
		Inherit,
		LTR,
		RTL
	};

	enum class LayoutFlexDirection : char
	{
		Column,
		ColumnReverse,
		Row,
		RowReverse
	};

	enum class LayoutJustify : char
	{
		FlexStart,
		Center,
		FlexEnd,
		SpaceBetween,
		SpaceAround,
		SpaceEvenly
	};

	enum class LayoutAlign : char
	{
		Auto,
		FlexStart,
		Center,
		FlexEnd,
		Stretch,
		Baseline,
		SpaceBetween,
		SpaceAround
	};

	enum class LayoutPositionType : char
	{
		Relative,
		Absolute
	};

	enum class LayoutWrap : char
	{
		NoWrap,
		Wrap,
		WrapReverse
	};

	enum class LayoutDisplay : char
	{
		Flex,
		None
	};
}