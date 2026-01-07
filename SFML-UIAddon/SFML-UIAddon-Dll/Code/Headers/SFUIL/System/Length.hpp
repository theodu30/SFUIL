#pragma once

#include "Exports.hpp"

namespace sfui
{
	enum class LengthUnit : char
	{
		Pixel,
		Percent,
		Em,
		Rem,
		Vw,
		Vh,
		Auto,
		Initial,
		None
	};

	struct SFUIL_API LengthContext
	{
		float parentSize = 0.f; // Context for Percent
		float fontSize = 16.0f; // Context for Em
		float rootFontSize = 16.0f; // Context for Rem
		float viewportWidth = 0.f; // Context for Vw
		float viewportHeight = 0.f; // Context for Vh
	};

	class SFUIL_API Length
	{
	private:
		float m_value = 0.f;
		LengthUnit m_unit = LengthUnit::Pixel;

		float m_defaultValue = 0.f;
		LengthUnit m_defaultUnit = LengthUnit::Pixel;

	public:
		Length() = default;
		~Length() = default;

		Length(float _value);
		Length(float _value, LengthUnit _unit);

		Length(const Length& _other) = default;
		Length& operator=(const Length& _other) = default;
		Length(Length&& _other) = default;
		Length& operator=(Length&& _other) = default;

		void set(float _value, LengthUnit _unit);
		void setDefault(float _value, LengthUnit _unit);

		float toPixels(const LengthContext& _ctx);

		bool isResolvable();

	public:
		static Length px(float _value);
		static Length percent(float _value);
		static Length em(float _value);
		static Length rem(float _value);
		static Length vw(float _value);
		static Length vh(float _value);

	};
}