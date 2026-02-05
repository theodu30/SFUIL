#pragma once

#include "../Exports.hpp"
#include "../Length.hpp"

namespace sfui
{
	enum class BackgroundSizeType : char
	{
		Length,
		Cover,
		Contain
	};

	class SFUIL_API BackgroundSize
	{
	private:
		BackgroundSizeType m_type;
		Length m_x;
		Length m_y;

	public:
		BackgroundSize(BackgroundSizeType _type);
		BackgroundSize(Length _x, Length _y);

		Length getX() const;
		void setX(Length _x);

		Length getY() const;
		void setY(Length _y);

		BackgroundSizeType getType() const;
		void setType(BackgroundSizeType _type);
	};
}