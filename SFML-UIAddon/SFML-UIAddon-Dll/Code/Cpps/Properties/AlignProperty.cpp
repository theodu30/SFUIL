#include "../../Headers/SFUIL/System/Properties/AlignProperty.hpp"

namespace sfui
{
	void AlignProperty::exportToXML(std::ostream& _stream) const
	{
		if (m_alignItemsDirty)
		{
			switch (m_alignItems)
			{
			case AlignItems::Auto: _stream << "align-items: auto; "; break;
			case AlignItems::FlexStart: _stream << "align-items: flex-start; "; break;
			case AlignItems::Center: _stream << "align-items: center; "; break;
			case AlignItems::FlexEnd: _stream << "align-items: flex-end; "; break;
			case AlignItems::Stretch: _stream << "align-items: stretch; "; break;
			default: break;
			}
		}

		if (m_justifyContentDirty)
		{
			switch (m_justifyContent)
			{
			case JustifyContent::FlexStart: _stream << "justify-content: flex-start; "; break;
			case JustifyContent::Center: _stream << "justify-content: center; "; break;
			case JustifyContent::FlexEnd: _stream << "justify-content: flex-end; "; break;
			case JustifyContent::SpaceBetween: _stream << "justify-content: space-between; "; break;
			case JustifyContent::SpaceAround: _stream << "justify-content: space-around; "; break;
			case JustifyContent::SpaceEvenly: _stream << "justify-content: space-evenly; "; break;
			default: break;
			}
		}

		if (m_alignSelfDirty)
		{
			switch (m_alignSelf)
			{
			case AlignSelf::Auto: _stream << "align-self: auto; "; break;
			case AlignSelf::FlexStart: _stream << "align-self: flex-start; "; break;
			case AlignSelf::Center: _stream << "align-self: center; "; break;
			case AlignSelf::FlexEnd: _stream << "align-self: flex-end; "; break;
			case AlignSelf::Stretch: _stream << "align-self: stretch; "; break;
			default: break;
			}
		}

		if (m_alignContentDirty)
		{
			switch (m_alignContent)
			{
			case AlignContent::Auto: _stream << "align-content: auto; "; break;
			case AlignContent::FlexStart: _stream << "align-content: flex-start; "; break;
			case AlignContent::Center: _stream << "align-content: center; "; break;
			case AlignContent::FlexEnd: _stream << "align-content: flex-end; "; break;
			case AlignContent::Stretch: _stream << "align-content: stretch; "; break;
			default: break;
			}
		}
	}

	AlignProperty::AlignItems AlignProperty::getAlignItems() const
	{
		return m_alignItems;
	}

	void AlignProperty::setAlignItems(AlignItems _alignItems)
	{
		m_alignItems = _alignItems;
		m_alignItemsDirty = true;
	}

	void AlignProperty::resetAlignItems()
	{
		m_alignItems = AlignItems::Stretch;
		m_alignItemsDirty = false;
	}

	void AlignProperty::setAlignItemsFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetAlignItems();
			return;
		}

		if (strcmp(_value, "auto") == 0)
			setAlignItems(AlignItems::Auto);
		else if (strcmp(_value, "flex-start") == 0)
			setAlignItems(AlignItems::FlexStart);
		else if (strcmp(_value, "center") == 0)
			setAlignItems(AlignItems::Center);
		else if (strcmp(_value, "flex-end") == 0)
			setAlignItems(AlignItems::FlexEnd);
		else if (strcmp(_value, "stretch") == 0)
			setAlignItems(AlignItems::Stretch);
		else
			resetAlignItems();
	}

	AlignProperty::JustifyContent AlignProperty::getJustifyContent() const
	{
		return m_justifyContent;
	}

	void AlignProperty::setJustifyContent(JustifyContent _justifyContent)
	{
		m_justifyContent = _justifyContent;
		m_justifyContentDirty = true;
	}

	void AlignProperty::resetJustifyContent()
	{
		m_justifyContent = JustifyContent::FlexStart;
		m_justifyContentDirty = false;
	}

	void AlignProperty::setJustifyContentFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetJustifyContent();
			return;
		}

		if (strcmp(_value, "flex-start") == 0)
			setJustifyContent(JustifyContent::FlexStart);
		else if (strcmp(_value, "center") == 0)
			setJustifyContent(JustifyContent::Center);
		else if (strcmp(_value, "flex-end") == 0)
			setJustifyContent(JustifyContent::FlexEnd);
		else if (strcmp(_value, "space-between") == 0)
			setJustifyContent(JustifyContent::SpaceBetween);
		else if (strcmp(_value, "space-around") == 0)
			setJustifyContent(JustifyContent::SpaceAround);
		else if (strcmp(_value, "space-evenly") == 0)
			setJustifyContent(JustifyContent::SpaceEvenly);
		else
			resetJustifyContent();
	}

	AlignProperty::AlignSelf AlignProperty::getAlignSelf() const
	{
		return m_alignSelf;
	}

	void AlignProperty::setAlignSelf(AlignSelf _alignSelf)
	{
		m_alignSelf = _alignSelf;
		m_alignSelfDirty = true;
	}

	void AlignProperty::resetAlignSelf()
	{
		m_alignSelf = AlignSelf::Auto;
		m_alignSelfDirty = false;
	}

	void AlignProperty::setAlignSelfFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetAlignSelf();
			return;
		}

		if (strcmp(_value, "auto") == 0)
			setAlignSelf(AlignSelf::Auto);
		else if (strcmp(_value, "flex-start") == 0)
			setAlignSelf(AlignSelf::FlexStart);
		else if (strcmp(_value, "center") == 0)
			setAlignSelf(AlignSelf::Center);
		else if (strcmp(_value, "flex-end") == 0)
			setAlignSelf(AlignSelf::FlexEnd);
		else if (strcmp(_value, "stretch") == 0)
			setAlignSelf(AlignSelf::Stretch);
		else
			resetAlignSelf();
	}

	AlignProperty::AlignContent AlignProperty::getAlignContent() const
	{
		return m_alignContent;
	}

	void AlignProperty::setAlignContent(AlignContent _alignContent)
	{
		m_alignContent = _alignContent;
		m_alignContentDirty = true;
	}

	void AlignProperty::resetAlignContent()
	{
		m_alignContent = AlignContent::FlexStart;
		m_alignContentDirty = false;
	}

	void AlignProperty::setAlignContentFromCStr(const char* _value)
	{
		if (_value == nullptr)
		{
			resetAlignContent();
			return;
		}

		if (strcmp(_value, "auto") == 0)
			setAlignContent(AlignContent::Auto);
		else if (strcmp(_value, "flex-start") == 0)
			setAlignContent(AlignContent::FlexStart);
		else if (strcmp(_value, "center") == 0)
			setAlignContent(AlignContent::Center);
		else if (strcmp(_value, "flex-end") == 0)
			setAlignContent(AlignContent::FlexEnd);
		else if (strcmp(_value, "stretch") == 0)
			setAlignContent(AlignContent::Stretch);
		else
			resetAlignContent();
	}

}
