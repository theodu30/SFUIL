#include "../Headers/SFUIL/System/Layout/LayoutDataAccess.hpp"

namespace sfui
{
	bool LayoutDataAccess::IsValid() const
	{
		return m_nodes.IsValid() && m_configs.IsValid();
	}

	LayoutDataAccess::LayoutDataAccess(int _manager, LayoutDataStore _nodes, LayoutDataStore _configs) : m_manager(_manager), m_nodes(_nodes), m_configs(_configs)
	{
	}

	LayoutNodeData& LayoutDataAccess::GetNodeData(LayoutHandle _handle)
	{
		return GetTypedNodeDataRef<LayoutNodeData>(_handle, LayoutNodeDataType::None);
	}

	LayoutStyleData& LayoutDataAccess::GetStyleData(LayoutHandle _handle)
	{
		return GetTypedNodeDataRef<LayoutStyleData>(_handle, LayoutNodeDataType::Style);
	}

	LayoutComputedData& LayoutDataAccess::GetComputedData(LayoutHandle _handle)
	{
		return GetTypedNodeDataRef<LayoutComputedData>(_handle, LayoutNodeDataType::Computed);
	}

	LayoutCacheData& LayoutDataAccess::GetCacheData(LayoutHandle _handle)
	{
		return GetTypedNodeDataRef<LayoutCacheData>(_handle, LayoutNodeDataType::Cache);
	}

	LayoutConfigData& LayoutDataAccess::GetConfigData(LayoutHandle _handle)
	{
		return GetTypedConfigDataRef<LayoutConfigData>(_handle, LayoutConfigDataType::Config);
	}

	LayoutMeasureFunction LayoutDataAccess::GetMeasureFonction(LayoutHandle _handle)
	{
		return LayoutManager::GetManager(m_manager).GetMeasureFunction(_handle);
	}

}