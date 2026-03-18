#include "../Headers/SFUIL/System/Layout/LayoutCachedMeasurement.hpp"

namespace sfui
{
	LayoutCachedMeasurement LayoutCachedMeasurement::Default;

	LayoutCachedMeasurement* LayoutCachedMeasurement::GetNextMeasurementCache()
	{
		return reinterpret_cast<LayoutCachedMeasurement*>(m_nextMeasurementCachePtr);
	}

	LayoutCachedMeasurement::LayoutCachedMeasurement() : availableWidth(0.f), availableHeight(0.f),
		parentWidth(0.f), parentHeight(0.f), widthMeasureMode(LayoutMeasureMode::Invalid), heightMeasureMode(LayoutMeasureMode::Invalid),
		computedWidth(-1.f), computedHeight(-1.f), m_nextMeasurementCachePtr(nullptr)
	{
	}
}
