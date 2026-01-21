#pragma once

#include "../../Exports.hpp"
#include "../StyleValue.hpp"

namespace sfui
{
	class StyleInt : public StyleValue<int>
	{
	private:
		int m_value;
		StyleKeyword m_keyword;

		StyleInt(int _value, StyleKeyword _keyword);

	public:
		const int getValue() const override;
		void setValue(const int _value) override;

		StyleKeyword getKeyword() const override;
		void setKeyword(StyleKeyword _keyword) override;

		StyleInt(int _value);
		StyleInt(StyleKeyword _keyword);
	};
}