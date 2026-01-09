#pragma once

#include "Exports.hpp"

namespace sfui
{
	template<typename T>
	class SFUIL_API StyleData
	{
	private:
		class RefCount
		{
		private:
			int m_refCount;

		public:
			T value;

			RefCount();

			int getRefCount();

			void call();
			void release();

			RefCount copy();

		};

		RefCount m_ref;

	public:

		int getRefCount();

		StyleData<T> call();

		void release();

		const T& read();

		T& write();

	public:
		static StyleData<T> create();

	};

}

#include "StyleData.hpp"