#include "../Headers/SFUIL/System/Layout/LayoutComputedData.hpp"
#include <cmath>
#include "../Headers/SFUIL/System/Layout/LayoutDefaults.hpp"

namespace sfui
{
	LayoutComputedData LayoutComputedData::GetDefault()
	{
		LayoutComputedData result{};
		result.direction = LayoutDirection::Inherit;
		result.computedFlexBasisGeneration = 0u;
		result.computedFlexBasis = NAN;
		result.generationCount = 0u;
		result.lastParentDirection = static_cast<LayoutDirection>(-1);
		result.lastPointScaleFactor = 1.f;
		result.dimensions[0] = LayoutDefaults::DimensionValues[0];
		result.dimensions[1] = LayoutDefaults::DimensionValues[1];
		result.measuredDimensions[0] = LayoutDefaults::DimensionValues[0];
		result.measuredDimensions[1] = LayoutDefaults::DimensionValues[1];

		return result;
	}

	float* LayoutComputedData::getMarginBuffer()
	{
		return margin;
	}

	float* LayoutComputedData::getBorderBuffer()
	{
		return border;
	}

	float* LayoutComputedData::getPaddingBuffer()
	{
		return padding;
	}

}
