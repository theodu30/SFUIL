#pragma once

namespace sfui
{
	const struct LayoutHandle
	{
		int index;
		int version;

		static LayoutHandle Undefined;

		bool IsUndefined();

		LayoutHandle(int _index, int _version);

		bool Equals(LayoutHandle _other);
	};
}