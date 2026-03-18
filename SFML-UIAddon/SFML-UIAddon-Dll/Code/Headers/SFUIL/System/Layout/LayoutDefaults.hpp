#pragma once

#include "../Datas/FixedBuffer.hpp"
#include "LayoutValue.hpp"

namespace sfui
{
	struct LayoutDefaults
	{
		static FixedBuffer<LayoutValue, 9> EdgeValuesUnit;
		static float DimensionValues[2];
		static FixedBuffer<LayoutValue, 2> DimensionValuesUnit;
		static FixedBuffer<LayoutValue, 2> DimensionValuesAutoUnit;

	private:
		static void StaticInit();
		struct StaticInitializer
		{
			StaticInitializer() { StaticInit(); }
		};
		static StaticInitializer s_initializer;
	};
}