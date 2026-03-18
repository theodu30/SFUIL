#pragma once

namespace sfui
{
	enum class LayoutMeasureMode : char
	{
		Undefined = 0,
		Exactly = 1,
		AtMost = 2,
		Invalid = -1
	};

	struct LayoutCachedMeasurement
	{
		static LayoutCachedMeasurement Default;

		float availableWidth;
		float availableHeight;
		float parentWidth;
		float parentHeight;

		LayoutMeasureMode widthMeasureMode;
		LayoutMeasureMode heightMeasureMode;

		float computedWidth;
		float computedHeight;

		LayoutCachedMeasurement* GetNextMeasurementCache();

		LayoutCachedMeasurement();

	private:
		void* m_nextMeasurementCachePtr = nullptr;

	};
}