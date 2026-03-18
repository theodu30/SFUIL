#pragma once
#include <cstdint>

namespace sfui
{
	struct LayoutConfigData
	{
		float pointScaleFactor;
		int managedMeasureFunctionIndex;
		int managedBaselineFunctionIndex;
		uint8_t shouldLog;

		static LayoutConfigData GetDefault();
	};
}