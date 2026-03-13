#pragma once

namespace sfui
{
	enum class LayoutUnit : char
	{
		Undefined,
		Point,
		Percent,
		Auto
	};

	class LayoutValue
	{
	private:
		float m_value;
		LayoutUnit m_unit;

		LayoutValue();

	public:
		LayoutValue(float _value);

		LayoutUnit getUnit() const;
		float getValue() const;

		static LayoutValue Point(float _value);
		static LayoutValue Undefined();
		static LayoutValue Auto();
		static LayoutValue Percent(float _value);

		bool operator==(const LayoutValue& _value);
		bool operator!=(const LayoutValue& _value);
		LayoutValue(const LayoutValue& _other);
		LayoutValue& operator=(const LayoutValue& _other);
		LayoutValue(LayoutValue&& _other) noexcept;
		LayoutValue& operator=(LayoutValue&& _other) noexcept;
	};
}