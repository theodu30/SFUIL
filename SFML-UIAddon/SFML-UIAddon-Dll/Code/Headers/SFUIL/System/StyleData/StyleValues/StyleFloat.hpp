#pragma once

#include "../../Exports.hpp"
#include "../StyleValue.hpp"

namespace sfui
{
	class StyleFloat : public StyleValue<float>
	{
	private:
		float m_value;
		StyleKeyword m_keyword;

		StyleFloat(float _value, StyleKeyword _keyword);

	public:
		const float getValue() const override;
		void setValue(const float _value) override;

		StyleKeyword getKeyword() const override;
		void setKeyword(StyleKeyword _keyword) override;

		StyleFloat(float _value);
		StyleFloat(StyleKeyword _keyword);
	};
}