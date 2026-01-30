#pragma once

#include "../../Exports.hpp"
#include "../../Datas/TransformOrigin.hpp"
#include "../../Datas/TransformTranslate.hpp"
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>

namespace sfui
{
	class SFUIL_API TransformData
	{
	public:
		TransformOrigin origin;

		TransformTranslate translate;

		sf::Vector2f scale;

		sf::Angle rotate;
	};
}
