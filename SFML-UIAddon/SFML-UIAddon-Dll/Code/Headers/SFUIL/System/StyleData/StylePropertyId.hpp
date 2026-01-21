#pragma once

#include "../Exports.hpp"

namespace sfui
{
	enum class SFUIL_API StylePropertyId
	{
		Unknown = 0,

		Opacity = 100,
		Display = 101,
		Visibility = 102,

		Position = 200,
		Top = 201,
		Right = 202,
		Bottom = 203,
		Left = 204,

		FlexBasic = 300,
		FlexShrink = 301,
		FlexGrow = 302,
		FlexDirection = 303,
		FlexWrap = 304,

		AlignItems = 400,
		JustifyContent = 401,
		AlignSelf = 402,
		AlignContent = 403,

		Width = 500,
		Height = 501,
		MinWidth = 502,
		MinHeight = 503,
		MaxWidth = 504,
		MinWidth = 505,
		AspectRatio = 506,

		Margin = 600,
		MarginTop = 601,
		MarginRight = 602,
		MarginBottom = 603,
		MarginLeft = 604,
		Padding = 605,
		PaddingTop = 606,
		PaddingRight = 607,
		PaddingBottom = 608,
		PaddingLeft = 609,

		TextFont = 700,
		FontStyle = 701,
		FontSize = 702,
		TextColor = 703,
		TextAlign = 704,

		BackgroundColor = 800,
		BackgroundImage = 801,
		BackgroundTint = 802,
		BackgroundRepeat = 803,
		BackgroundWidth = 804,
		BackgroundHeight = 805,
		BackgroundPositionX = 806,
		BackgroundPositionY = 807,
		BackgroundScaleMode = 808,

		BorderColor = 900,
		BorderWidth = 901,
		BorderHeight = 902,

		OriginX = 1000,
		OriginY = 1001,
		TranslateX = 1002,
		TranslateY = 1003,
		ScaleX = 1004,
		ScaleY = 1005,
		Rotate = 1006
	};

}
