#include "../Headers/SFUIL/System/Layout/LayoutDefaults.hpp"

namespace sfui
{
	FixedBuffer<LayoutValue, 9> LayoutDefaults::EdgeValuesUnit;
	float LayoutDefaults::DimensionValues[2];
	FixedBuffer<LayoutValue, 2> LayoutDefaults::DimensionValuesUnit;
	FixedBuffer<LayoutValue, 2> LayoutDefaults::DimensionValuesAutoUnit;
	LayoutDefaults::StaticInitializer LayoutDefaults::s_initializer;

	void LayoutDefaults::StaticInit()
	{
		for (int i = 0; i < 9; ++i)
		{
			EdgeValuesUnit[i] = LayoutValue::Undefined();
		}

		DimensionValues[0] = NAN;
		DimensionValues[1] = NAN;

		DimensionValuesUnit[0] = LayoutValue::Undefined();
		DimensionValuesUnit[1] = LayoutValue::Undefined();
		
		DimensionValuesAutoUnit[0] = LayoutValue::Auto();
		DimensionValuesAutoUnit[1] = LayoutValue::Auto();
	}

}
