#pragma once

#include "LayoutEnums.hpp"

namespace sfui
{
	struct LayoutComputedData
	{
		float position[4];
		float dimensions[2];
		float margin[6];
		float border[6];
		float padding[6];
		LayoutDirection direction;
		unsigned int computedFlexBasisGeneration;
		float computedFlexBasis;
		unsigned int generationCount;
		LayoutDirection lastParentDirection;
		float lastPointScaleFactor;
		float measuredDimensions[2];

		static LayoutComputedData GetDefault();

		float* getMarginBuffer();
		float* getBorderBuffer();
		float* getPaddingBuffer();
	};
}