#pragma once

namespace sfui
{
	enum class DisplayEnum : char
	{
		Flex,
		None
	};

	enum class VisibilityEnum : char
	{
		Visible,
		Hidden
	};

	enum class PositionEnum : char
	{
		Relative,
		Absolute
	};

	enum class FlexDirectionEnum : char
	{
		Column,
		ColumnReverse,
		Row,
		RowReverse
	};

	enum class FlexWrapEnum : char
	{
		NoWrap,
		Wrap,
		WrapReverse
	};

	enum class AlignEnum : char
	{
		Auto,
		FlexStart,
		Center,
		FlexEnd,
		Stretch
	};

	enum class JustifyEnum : char
	{
		FlexStart,
		Center,
		FlexEnd,
		SpaceBetween,
		SpaceAround,
		SpaceEvenly
	};

	enum class FontStyleEnum : char
	{
		Normal,
		Italic,
		Bold,
		ItalicBold
	};

	enum class TextAlignEnum : char
	{
		UpperLeft,
		UpperCenter,
		UpperRight,
		MiddleLeft,
		MiddleCenter,
		MiddleRight,
		LowerLeft,
		LowerCenter,
		LowerRight
	};

}
