#include "../Headers/SFUIL/System/Datas/BackgroundSize.hpp"

namespace sfui
{
	BackgroundSize::BackgroundSize(BackgroundSizeType _type) : m_type(_type), m_x(0.f), m_y(0.f)
	{
	}

	BackgroundSize::BackgroundSize(Length _x, Length _y) : m_type(BackgroundSizeType::Length), m_x(_x), m_y(_y)
	{
	}

	Length BackgroundSize::getX() const
	{
		return m_x;
	}

	void BackgroundSize::setX(Length _x)
	{
		m_x = _x;
		m_type = BackgroundSizeType::Length;
	}

	Length BackgroundSize::getY() const
	{
		return m_y;
	}

	void BackgroundSize::setY(Length _y)
	{
		m_y = _y;
		m_type = BackgroundSizeType::Length;
	}

	BackgroundSizeType BackgroundSize::getType() const
	{
		return m_type;
	}

	void BackgroundSize::setType(BackgroundSizeType _type)
	{
		m_type = _type;
		m_x = 0.f;
		m_y = 0.f;
	}

}