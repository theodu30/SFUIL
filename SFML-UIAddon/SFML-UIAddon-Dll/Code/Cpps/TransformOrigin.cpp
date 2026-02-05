#include "../Headers/SFUIL/System/Datas/TransformOrigin.hpp"

namespace sfui
{
	TransformOrigin::TransformOrigin(Length _x, Length _y) : m_x(_x), m_y(_y)
	{
	}

	TransformOrigin::TransformOrigin(sf::Vector2f _v) : TransformOrigin(_v.x, _v.y)
	{
	}

	Length TransformOrigin::getX() const
	{
		return m_x;
	}

	Length TransformOrigin::getY() const
	{
		return m_y;
	}

	void TransformOrigin::setX(Length _x)
	{
		m_x = _x;
	}

	void TransformOrigin::setY(Length _y)
	{
		m_y = _y;
	}

}
