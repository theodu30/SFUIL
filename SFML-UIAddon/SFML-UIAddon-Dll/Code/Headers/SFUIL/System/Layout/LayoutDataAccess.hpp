#pragma once

#include "../Exports.hpp"
#include "LayoutDataStore.hpp"

namespace sfui
{
	enum class LayoutNodeDataType : char
	{
		None,
		Style,
		Computed,
		Cache
	};

	enum class LayoutConfigDataType : char
	{
		Config
	};

	class SFUIL_API LayoutDataAccess
	{
	private:
		const int m_manager;
		const LayoutDataStore m_nodes;
		const LayoutDataStore m_configs;

		template <typename T>
		T& GetTypedNodeDataRef(LayoutHandle _handle, LayoutNodeDataType _type)
		{
			return *static_cast<const T*>(m_nodes.GetComponentDataPtr(_handle.index, static_cast<int>(_type));
		}

		template <typename T>
		T& GetTypedConfigDataRef(LayoutHandle _handle, LayoutConfigDataType _type)
		{
			return *static_cast<const T*>(m_configs.GetComponentDataPtr(_handle.index, static_cast<int>(_type));
		}

	public:
		bool IsValid();

		LayoutDataAccess(int _manager, LayoutDataStore _nodes, LayoutDataStore _configs);

		LayoutNodeData& GetNodeData(LayoutHandle _handle);
	};
}