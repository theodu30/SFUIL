#include "../Headers/SFUIL/System/Datas/TransformTranslate.hpp"

namespace sfui
{
	TransformTranslate::TransformTranslate(Length _x, Length _y) : m_x(_x), m_y(_y)
	{
	}

	TransformTranslate::TransformTranslate(sf::Vector2f _v) : TransformTranslate(_v.x, _v.y)
	{
	}

	Length TransformTranslate::getX() const
	{
		return m_x;
	}

	Length TransformTranslate::getY() const
	{
		return m_y;
	}

	void TransformTranslate::setX(Length _x)
	{
		m_x = _x;
	}

	void TransformTranslate::setY(Length _y)
	{
		m_y = _y;
	}

	TransformTranslate TransformTranslate::Initial()
	{
		return TransformTranslate(0.f, 0.f);
	}

}