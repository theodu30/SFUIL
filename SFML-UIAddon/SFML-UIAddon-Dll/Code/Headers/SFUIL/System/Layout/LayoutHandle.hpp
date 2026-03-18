#pragma once

namespace sfui
{
	struct LayoutHandle
	{
		int index;
		int version;

		static LayoutHandle Undefined;

		LayoutHandle();
		LayoutHandle(int _index, int _version);

		bool IsUndefined() const;

		bool Equals(LayoutHandle _other) const;
	};
}