#pragma once

#include "../Interfaces/IDisposable.hpp"
#include <vector>
#include "LayoutDataStore.hpp"

namespace sfui
{
	class LayoutManager : public IDisposable
	{
	private:
		enum class SharedManagerState : char
		{
			Uninitialized,
			Initialized,
			Shutdown
		};

		static SharedManagerState s_initialized;
		static bool s_appDomainUnloadRegistered;
		static LayoutManager s_sharedInstance;
		static std::vector<LayoutManager*> s_managers;

		const int k_initialConfigCapacity = 32;

		int m_index;

		LayoutDataStore m_nodes;
		LayoutDataStore m_configs;

	public:
		const int k_capacityBig = 65536;
		const int k_capacitySmall = 16;

	};
}