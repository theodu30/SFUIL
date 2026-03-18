#pragma once

#include "../Datas/FixedBuffer.hpp"
#include "LayoutValue.hpp"
#include "LayoutHandle.hpp"
#include "LayoutList.hpp"

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
		FlexStatus m_status;

		friend FlexStatus operator|(FlexStatus a, FlexStatus b);
		friend FlexStatus operator&(FlexStatus a, FlexStatus b);
		friend FlexStatus operator~(FlexStatus a);

	public:
		FixedBuffer<LayoutValue, 2> resolvedDimensions;
		int managedOwnerIndex;
		int lineIndex;
		LayoutHandle config;
		LayoutHandle parent;
		LayoutHandle nextChild;
		LayoutList<LayoutHandle> children;

		bool GetHasNewLayout() const;
		void SetHasNewLayout(bool _value);

		bool IsDirty() const;
		void SetDirty(bool _value);

		bool GetUsesMeasure() const;
		void SetUsesMeasure(bool _value);

		bool GetUsesBaseLine() const;
		void SetUsesBaseLine(bool _value);

	};
}