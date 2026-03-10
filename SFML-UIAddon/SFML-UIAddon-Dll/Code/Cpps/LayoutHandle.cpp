#include "../Headers/SFUIL/System/Layout/LayoutHandle.hpp"

namespace sfui
{
	LayoutHandle LayoutHandle::Undefined(0, 0);

	bool LayoutHandle::IsUndefined()
	{
		return Equals(Undefined);
	}

	LayoutHandle::LayoutHandle(int _index, int _version) : index(_index), version(_version)
	{
	}

	bool LayoutHandle::Equals(LayoutHandle _other)
	{
		return index == _other.index && version == _other.version;
	}
}