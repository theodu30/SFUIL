#pragma once

#include "LayoutCachedMeasurement.hpp"

namespace sfui
{
	struct LayoutCacheData
	{
		static LayoutCacheData Default;

		LayoutCachedMeasurement cachedLayout;

		int MeasurementCacheCount();

		void ClearCachedMeasurements();

		LayoutCacheData();

	private:
		void ClearCachedMeasurements(void* _layoutCacheData);
	};
}