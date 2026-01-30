#include "../Headers/SFUIL/System/Datas/BackgroundPosition.hpp"

namespace sfui
{
	BackgroundPosition::BackgroundPosition(BackgroundPositionKeyword _keyword) : BackgroundPosition(_keyword, 0.f)
	{
	}

	BackgroundPosition::BackgroundPosition(BackgroundPositionKeyword _keyword, Length _offset) : m_keyword(_keyword), m_offset(_offset)
	{
	}

	BackgroundPositionKeyword BackgroundPosition::getKeyword() const
	{
		return m_keyword;
	}

	void BackgroundPosition::setKeyword(BackgroundPositionKeyword _keyword)
	{
		m_keyword = _keyword;
	}

	Length BackgroundPosition::getOffset() const
	{
		return m_offset;
	}

	void BackgroundPosition::setOffset(Length _offset)
	{
		m_offset = _offset;
	}

}