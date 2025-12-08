#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API AlignProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class AlignItems : char
		{
			Auto,
			FlexStart,
			Center,
			FlexEnd,
			Stretch
		};

		[[nodiscard]] AlignItems getAlignItems() const;
		void setAlignItems(AlignItems _alignItems);
		void resetAlignItems();

		enum class JustifyContent : char
		{
			FlexStart,
			Center,
			FlexEnd,
			SpaceBetween,
			SpaceAround,
			SpaceEvenly
		};

		[[nodiscard]] JustifyContent getJustifyContent() const;
		void setJustifyContent(JustifyContent _justifyContent);
		void resetJustifyContent();

		enum class AlignSelf : char
		{
			Auto,
			FlexStart,
			Center,
			FlexEnd,
			Stretch
		};

		[[nodiscard]] AlignSelf getAlignSelf() const;
		void setAlignSelf(AlignSelf _alignSelf);
		void resetAlignSelf();

		enum class AlignContent : char
		{
			Auto,
			FlexStart,
			Center,
			FlexEnd,
			Stretch
		};

		[[nodiscard]] AlignContent getAlignContent() const;
		void setAlignContent(AlignContent _alignContent);
		void resetAlignContent();

	private:
		AlignItems m_alignItems = AlignItems::Stretch;
		bool m_alignItemsDirty = false;
		JustifyContent m_justifyContent = JustifyContent::FlexStart;
		bool m_justifyContentDirty = false;
		AlignSelf m_alignSelf = AlignSelf::Auto;
		bool m_alignSelfDirty = false;
		AlignContent m_alignContent = AlignContent::FlexStart;
		bool m_alignContentDirty = false;
	};
}