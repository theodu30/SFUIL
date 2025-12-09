#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API FlexProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class BasicType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct Basic
		{
			float value = 0.f;
			BasicType type = BasicType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const Basic& getFlexBasic() const;
		void setFlexBasic(const Basic& _value);
		void setFlexBasic(float _value, BasicType _type);
		void setFlexBasic(float _value);
		void resetFlexBasic();
		void setFlexBasicFromCStr(const char* _value);


		[[nodiscard]] const float& getFlexShrink() const;
		void setFlexShrink(float _value);
		void resetFlexShrink();
		void setFlexShrinkFromCStr(const char* _value);

		[[nodiscard]] const float& getFlexGrow() const;
		void setFlexGrow(float _value);
		void resetFlexGrow();
		void setFlexGrowFromCStr(const char* _value);

		enum class Direction : char
		{
			Column,
			ColumnReverse,
			Row,
			RowReverse
		};

		[[nodiscard]] Direction getFlexDirection() const;
		void setFlexDirection(Direction _direction);
		void resetFlexDirection();
		void setFlexDirectionFromCStr(const char* _value);

		enum class Warp : char
		{
			NoWrap,
			Wrap,
			WrapReverse
		};

		[[nodiscard]] Warp getFlexWrap() const;
		void setFlexWrap(Warp _warp);
		void resetFlexWrap();
		void setFlexWrapFromCStr(const char* _value);

	private:
		Basic m_flexBasis;
		bool m_flexBasisDirty = false;
		float m_flexShrink = 1.f;
		bool m_flexShrinkDirty = false;
		float m_flexGrow = 1.f;
		bool m_flexGrowDirty = false;
		Direction m_flexDirection = Direction::Column;
		bool m_flexDirectionDirty = false;
		Warp m_flexWrap = Warp::NoWrap;
		bool m_flexWrapDirty = false;
	};
}