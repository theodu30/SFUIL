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

		constexpr Length(float _value, Unit _unit);

	public:
		constexpr Length();
		~Length() = default;

		constexpr Length(const Length& _other);
		constexpr Length& operator=(const Length& _other);
		constexpr Length(Length&& _other) noexcept;
		constexpr Length& operator=(Length&& _other) noexcept;

		constexpr Length(float _value);
		constexpr Length(float _value, LengthUnit _unit);

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

	namespace Literals
	{
		inline sfui::Length operator""_px(long double _value);

		inline sfui::Length operator""_px(unsigned long long _value);

		inline sfui::Length operator""_pct(long double _value);

		inline sfui::Length operator""_pct(unsigned long long _value);

		inline sfui::Length operator""_em(long double _value);

		inline sfui::Length operator""_em(unsigned long long _value);

		inline sfui::Length operator""_rem(long double _value);

		inline sfui::Length operator""_rem(unsigned long long _value);

		inline sfui::Length operator""_vw(long double _value);

		inline sfui::Length operator""_vw(unsigned long long _value);

		inline sfui::Length operator""_vh(long double _value);

		inline sfui::Length operator""_vh(unsigned long long _value);

	}

}