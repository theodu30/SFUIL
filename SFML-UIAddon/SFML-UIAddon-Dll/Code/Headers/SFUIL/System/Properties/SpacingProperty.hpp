#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API SpacingProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class MarginType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct MarginValue
		{
			float value = 0.f;
			MarginType type = MarginType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const MarginValue& getMarginTop() const;
		void setMarginTop(const MarginValue& _value);
		void setMarginTop(float _value, MarginType _type);
		void setMarginTop(float _value);
		void resetMarginTop();

		[[nodiscard]] const MarginValue& getMarginRight() const;
		void setMarginRight(const MarginValue& _value);
		void setMarginRight(float _value, MarginType _type);
		void setMarginRight(float _value);
		void resetMarginRight();

		[[nodiscard]] const MarginValue& getMarginBottom() const;
		void setMarginBottom(const MarginValue& _value);
		void setMarginBottom(float _value, MarginType _type);
		void setMarginBottom(float _value);
		void resetMarginBottom();

		[[nodiscard]] const MarginValue& getMarginLeft() const;
		void setMarginLeft(const MarginValue& _value);
		void setMarginLeft(float _value, MarginType _type);
		void setMarginLeft(float _value);
		void resetMarginLeft();

		enum class PaddingType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct PaddingValue
		{
			float value = 0.f;
			PaddingType type = PaddingType::Pixels;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const PaddingValue& getPaddingTop() const;
		void setPaddingTop(const PaddingValue& _value);
		void setPaddingTop(float _value, PaddingType _type);
		void setPaddingTop(float _value);
		void resetPaddingTop();

		[[nodiscard]] const PaddingValue& getPaddingRight() const;
		void setPaddingRight(const PaddingValue& _value);
		void setPaddingRight(float _value, PaddingType _type);
		void setPaddingRight(float _value);
		void resetPaddingRight();

		[[nodiscard]] const PaddingValue& getPaddingBottom() const;
		void setPaddingBottom(const PaddingValue& _value);
		void setPaddingBottom(float _value, PaddingType _type);
		void setPaddingBottom(float _value);
		void resetPaddingBottom();

		[[nodiscard]] const PaddingValue& getPaddingLeft() const;
		void setPaddingLeft(const PaddingValue& _value);
		void setPaddingLeft(float _value, PaddingType _type);
		void setPaddingLeft(float _value);
		void resetPaddingLeft();

	private:
		MarginValue m_marginTop;
		bool m_marginTopDirty = false;
		MarginValue m_marginRight;
		bool m_marginRightDirty = false;
		MarginValue m_marginBottom;
		bool m_marginBottomDirty = false;
		MarginValue m_marginLeft;
		bool m_marginLeftDirty = false;
		PaddingValue m_paddingTop;
		bool m_paddingTopDirty = false;
		PaddingValue m_paddingRight;
		bool m_paddingRightDirty = false;
		PaddingValue m_paddingBottom;
		bool m_paddingBottomDirty = false;
		PaddingValue m_paddingLeft;
		bool m_paddingLeftDirty = false;
	};
}