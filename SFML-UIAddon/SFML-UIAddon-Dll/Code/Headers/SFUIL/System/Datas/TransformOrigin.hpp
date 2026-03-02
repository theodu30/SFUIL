#pragma once

#include "../Exports.hpp"
#include "../Length.hpp"
#include <SFML/System/Vector2.hpp>

namespace sfui
{
	class TransformOrigin
	{
	private:
		Length m_x;
		Length m_y;

	public:
		TransformOrigin();

		TransformOrigin(Length _x, Length _y);
		TransformOrigin(sf::Vector2f _v);

		Length getX() const;
		Length getY() const;

		void setX(Length _x);
		void setY(Length _y);

		static TransformOrigin Initial();
	};
}