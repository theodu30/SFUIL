#pragma once

#include <type_traits>
#include "../../Exports.hpp"
#include "../StyleValue.hpp"

namespace sfui
{
	template<typename E>
	concept EnumType = std::is_enum_v<E>;

	template<EnumType E>
	class StyleEnum : public StyleValue<E>
	{
	private:
		E m_value;
		StyleKeyword m_keyword;

		StyleEnum(E _value, StyleKeyword _keyword) : m_value(_value), m_keyword(_keyword)
		{
		}

	public:
		const E getValue() const override
		{
			return (m_keyword == StyleKeyword::Undefined) ? m_value : E();
		}

		void setValue(const E _value) override
		{
			m_value = _value;
			m_keyword = StyleKeyword::Undefined;
		}

		StyleKeyword getKeyword() const override
		{
			return m_keyword;
		}

		void setKeyword(StyleKeyword _keyword) override
		{
			m_keyword = _keyword;
		}

		StyleEnum(E _value) : StyleEnum<E>(_value, StyleKeyword::Undefined)
		{
		}

		StyleEnum(StyleKeyword _keyword) : StyleEnum<E>(E(), _keyword)
		{
		}
	};

}