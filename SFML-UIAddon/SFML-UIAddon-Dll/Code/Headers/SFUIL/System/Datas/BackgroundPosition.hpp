#pragma once

#include "../Exports.hpp"
#include "../Length.hpp"

namespace sfui
{
	enum class BackgroundPositionKeyword : char
	{
		Center,
		Top,
		Bottom,
		Left,
		Right
	};

	class BackgroundPosition
	{
	private:
		Length m_offset;
		BackgroundPositionKeyword m_keyword;

	public:
		BackgroundPosition();

		BackgroundPosition(BackgroundPositionKeyword _keyword);
		BackgroundPosition(BackgroundPositionKeyword _keyword, Length _offset);

		BackgroundPositionKeyword getKeyword() const;
		void setKeyword(BackgroundPositionKeyword _keyword);

		Length getOffset() const;
		void setOffset(Length _offset);

		static BackgroundPosition Initial();
	};
}