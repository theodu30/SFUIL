#pragma once

#include "../../Exports.hpp"
#include "../../Length.hpp"
#include "../StyleValue.hpp"

namespace sfui
{
	class StyleLength : public StyleValue<Length>
	{
	private:
		Length m_value;
		StyleKeyword m_keyword;

		StyleLength(Length _value, StyleKeyword _keyword);

	public:
		const Length getValue() const override;
		void setValue(const Length _value) override;

		StyleKeyword getKeyword() const override;
		void setKeyword(StyleKeyword _keyword) override;

		StyleLength(float _value);
		StyleLength(Length _value);
		StyleLength(StyleKeyword _keyword);
	};
}