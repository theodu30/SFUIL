#pragma once

#include "../../Exports.hpp"

namespace sfui
{
	enum class SFUIL_API DisplayEnum : char
	{
		Flex,
		None
	};

	enum class SFUIL_API VisibilityEnum : char
	{
		Visible,
		Hidden
	};

	enum class SFUIL_API PositionEnum : char
	{
		Relative,
		Absolute
	};

	enum class SFUIL_API FlexDirectionEnum : char
	{
		Column,
		ColumnReverse,
		Row,
		RowReverse
	};

	enum class SFUIL_API FlexWrapEnum : char
	{
		NoWrap,
		Wrap,
		WrapReverse
	};

	enum class SFUIL_API AlignEnum : char
	{
		Auto,
		FlexStart,
		Center,
		FlexEnd,
		Stretch
	};

	enum class SFUIL_API JustifyEnum : char
	{
		FlexStart,
		Center,
		FlexEnd,
		SpaceBetween,
		SpaceAround,
		SpaceEvenly
	};

	enum class SFUIL_API FontStyleEnum : char
	{
		Normal,
		Italic,
		Bold,
		ItalicBold
	};

	enum class SFUIL_API TextAlignEnum : char
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
