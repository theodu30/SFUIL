#include "../Headers/SFUIL/System/Layout/LayoutCacheData.hpp"
#include <corecrt_malloc.h>

namespace sfui
{
	LayoutCacheData LayoutCacheData::Default;

	int LayoutCacheData::MeasurementCacheCount()
	{
		int num = 0;
		for (LayoutCachedMeasurement* nextCache = cachedLayout.GetNextMeasurementCache(); nextCache != nullptr; nextCache = nextCache->GetNextMeasurementCache())
		{
			++num;
		}

		return num;
	}

	void LayoutCacheData::ClearCachedMeasurements()
	{
		if (cachedLayout.GetNextMeasurementCache())
		{
			ClearCachedMeasurements(&cachedLayout);
		}
	}

	LayoutCacheData::LayoutCacheData() : cachedLayout(LayoutCachedMeasurement::Default)
	{
	}

	void LayoutCacheData::ClearCachedMeasurements(void* _layoutCacheData)
	{
		LayoutCachedMeasurement* current = static_cast<LayoutCachedMeasurement*>(_layoutCacheData);

		LayoutCachedMeasurement* next = current->GetNextMeasurementCache();

		while (next)
		{
			LayoutCachedMeasurement* temp = next->GetNextMeasurementCache();
			_aligned_free(next);
			next = temp;
		}

		*current = LayoutCachedMeasurement{};
	}

}