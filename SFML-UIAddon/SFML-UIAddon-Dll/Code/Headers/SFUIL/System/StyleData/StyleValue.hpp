#pragma once

#include "../Exports.hpp"
#include "StyleKeyword.hpp"

namespace sfui
{
	template<typename T>
	class StyleValue
	{
	public:
		virtual const T getValue() const = 0;
		virtual void setValue(const T _value) = 0;

		virtual StyleKeyword getKeyword() const = 0;
		virtual void setKeyword(StyleKeyword _keyword) = 0;
	};
}