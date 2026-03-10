#pragma once

#include "../Exports.hpp"

namespace sfui
{
	class SFUIL_API IDisposable
	{
	public:
		virtual void Dispose() = 0;
	};
}