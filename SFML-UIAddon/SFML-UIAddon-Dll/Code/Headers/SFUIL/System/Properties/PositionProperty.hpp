#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API PositionProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class Mode : char
		{
			Relative,
			Absolute
		};

		[[nodiscard]] Mode getMode() const;
		void setMode(Mode _mode);
		void resetMode();

		enum class ValueType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct Value
		{
			float value = 0.f;
			ValueType type = ValueType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		[[nodiscard]] const Value& getTop() const;
		void setTop(const Value& _value);
		void setTop(float _value, ValueType _type);
		void setTop(float _value);
		void resetTop();

		[[nodiscard]] const Value& getRight() const;
		void setRight(const Value& _value);
		void setRight(float _value, ValueType _type);
		void setRight(float _value);
		void resetRight();

		[[nodiscard]] const Value& getBottom() const;
		void setBottom(const Value& _value);
		void setBottom(float _value, ValueType _type);
		void setBottom(float _value);
		void resetBottom();

		[[nodiscard]] const Value& getLeft() const;
		void setLeft(const Value& _value);
		void setLeft(float _value, ValueType _type);
		void setLeft(float _value);
		void resetLeft();

	private:
		Mode m_mode = Mode::Relative;
		bool m_modeDirty = false;
		Value m_top;
		bool m_topDirty = false;
		Value m_right;
		bool m_rightDirty = false;
		Value m_bottom;
		bool m_bottomDirty = false;
		Value m_left;
		bool m_leftDirty = false;
	};
}