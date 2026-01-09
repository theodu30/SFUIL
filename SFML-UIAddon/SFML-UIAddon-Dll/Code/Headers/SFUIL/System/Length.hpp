#pragma once

#include "Exports.hpp"

namespace sfui
{
	enum class LengthUnit : char
	{
		Pixel,
		Percent
	};

	class SFUIL_API Length
	{
	private:
		enum class Unit : char
		{
			Pixel,
			Percent,
			Em,
			Rem,
			Vw,
			Vh,
			Auto,
			None
		};

		float m_value;
		Unit m_unit;

		Length(float _value, Unit _unit);

	public:
		Length();
		~Length() = default;

		Length(const Length& _other);
		Length& operator=(const Length& _other);
		Length(Length&& _other) noexcept;
		Length& operator=(Length&& _other) noexcept;

		Length(float _value);
		Length(float _value, LengthUnit _unit);

		bool isAuto() const;
		bool isNone() const;

		float getValue() const;
		void setValue(float _value);

		LengthUnit getUnit() const;
		void setUnit(LengthUnit _unit);

	public:
		static Length Pixels(float _value);
		static Length Percent(float _value);
		static Length Em(float _value);
		static Length Rem(float _value);
		static Length Vw(float _value);
		static Length Vh(float _value);
		static Length Auto();
		static Length None();

	};

	inline Length operator""_px(long double _value)
	{
		return Length::Pixels(static_cast<float>(_value));
	}

	inline Length operator""_pct(long double _value)
	{
		return Length::Percent(static_cast<float>(_value));
	}

	inline Length operator""_em(long double _value)
	{
		return Length::Em(static_cast<float>(_value));
	}

	inline Length operator""_rem(long double _value)
	{
		return Length::Rem(static_cast<float>(_value));
	}

	inline Length operator""_vw(long double _value)
	{
		return Length::Vw(static_cast<float>(_value));
	}

	inline Length operator""_vh(long double _value)
	{
		return Length::Vh(static_cast<float>(_value));
	}

}