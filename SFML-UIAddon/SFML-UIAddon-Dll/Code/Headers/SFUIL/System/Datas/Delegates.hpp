#pragma once

namespace sfui
{
	class UIVisualElement;
	class LayoutNode;
	enum class LayoutMeasureMode;
	struct LayoutSize;

	typedef void (*LayoutMeasureFunction) (const UIVisualElement& _ve, LayoutNode& _node, float _width, LayoutMeasureMode _widthMode, float _height, LayoutMeasureMode _heightMode, LayoutSize& _outResult);
}