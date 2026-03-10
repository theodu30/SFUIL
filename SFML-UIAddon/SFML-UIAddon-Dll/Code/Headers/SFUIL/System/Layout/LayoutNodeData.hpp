#pragma once

namespace sfui
{
	struct LayoutNodeData
	{
		enum class FlexStatus
		{
			IsDirty = 1,
			HasNewLayout = 4,
			DependsOnParentSize = 0x40,
			UsesMeasure = 0x80,
			UsesBaseLine = 0x100,
			Fixed = 8,
			MinViolation = 0x10,
			MaxViolation = 0x20
		};
	};
}