#pragma once

namespace sfui
{
	struct ComponentType
	{
		int size;

		template <typename T>
		static ComponentType Create()
		{
			ComponentType result{sizeof(T)};
			return result;
		}
	};
}