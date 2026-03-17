#pragma once

#include "../Datas/FixedBuffer.hpp"
#include "LayoutValue.hpp"

namespace sfui
{
	class LayoutNodeData
	{
	private:
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

		float m_targetSize;

	public:
		FixedBuffer<LayoutValue, 2> resolvedDimensions;
		int managedOwnerIndex;
		int lineIndex;
		LayoutHandle config;
		LayoutHandle parent;
		LayoutHandle nextChild;

	};
}