#pragma once

#include "../Exports.hpp"
#include "IDisposable.hpp"

namespace sfui
{
	template <typename T>
	class IEnumerator : public IDisposable
	{
	public:
		virtual T Current() const = 0;
		virtual bool MoveNext() = 0;
		virtual void Reset() = 0;
		virtual ~IEnumerator() = default;
	};
}