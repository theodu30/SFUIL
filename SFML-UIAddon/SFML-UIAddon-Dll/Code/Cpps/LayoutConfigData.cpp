#include "../Headers/SFUIL/System/Layout/LayoutConfigData.hpp"

namespace sfui
{
	LayoutConfigData LayoutConfigData::GetDefault()
	{
		LayoutConfigData result{};
		result.pointScaleFactor = 1.f;
		result.shouldLog = false;
		result.managedMeasureFunctionIndex = 0;
		result.managedBaselineFunctionIndex = 0;

		return result;
	}
}