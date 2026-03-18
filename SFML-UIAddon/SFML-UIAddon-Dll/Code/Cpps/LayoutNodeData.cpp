#include "../Headers/SFUIL/System/Layout/LayoutNodeData.hpp"

namespace sfui
{
	LayoutNodeData::FlexStatus operator|(LayoutNodeData::FlexStatus a, LayoutNodeData::FlexStatus b)
	{
		return static_cast<LayoutNodeData::FlexStatus>(static_cast<int>(a) | static_cast<int>(b));
	}

	LayoutNodeData::FlexStatus operator&(LayoutNodeData::FlexStatus a, LayoutNodeData::FlexStatus b)
	{
		return static_cast<LayoutNodeData::FlexStatus>(static_cast<int>(a) & static_cast<int>(b));
	}

	LayoutNodeData::FlexStatus operator~(LayoutNodeData::FlexStatus a)
	{
		return static_cast<LayoutNodeData::FlexStatus>(~static_cast<int>(a));
	}

	bool LayoutNodeData::GetHasNewLayout() const
	{
		return (m_status & FlexStatus::HasNewLayout) == FlexStatus::HasNewLayout;
	}

	void LayoutNodeData::SetHasNewLayout(bool _value)
	{
		m_status = (_value ? (m_status | FlexStatus::HasNewLayout) : (m_status & ~FlexStatus::HasNewLayout));
	}

	bool LayoutNodeData::IsDirty() const
	{
		return (m_status & FlexStatus::IsDirty) == FlexStatus::IsDirty;
	}

	void LayoutNodeData::SetDirty(bool _value)
	{
		m_status = (_value ? (m_status | FlexStatus::IsDirty) : (m_status & ~FlexStatus::IsDirty));
	}

	bool LayoutNodeData::GetUsesMeasure() const
	{
		return (m_status & FlexStatus::UsesMeasure) == FlexStatus::UsesMeasure;
	}

	void LayoutNodeData::SetUsesMeasure(bool _value)
	{
		m_status = (_value ? (m_status | FlexStatus::UsesMeasure) : (m_status & ~FlexStatus::UsesMeasure));
	}

	bool LayoutNodeData::GetUsesBaseLine() const
	{
		return (m_status & FlexStatus::UsesBaseLine) == FlexStatus::UsesBaseLine;
	}

	void LayoutNodeData::SetUsesBaseLine(bool _value)
	{
		m_status = (_value ? (m_status | FlexStatus::UsesBaseLine) : (m_status & ~FlexStatus::UsesBaseLine));
	}

}