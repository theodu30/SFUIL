#pragma once

#include "../Exports.hpp"
#include "../Interfaces/IDisposable.hpp"
#include "../Datas/ComponentType.hpp"
#include "LayoutHandle.hpp"
#include <cstdint>
#include <span>

namespace sfui
{
	class SFUIL_API LayoutDataStore : public IDisposable
	{
	private:
		struct Chunk
		{
			uint8_t* buffer;
		};

		class ComponentDataStore : public IDisposable
		{
		private:
			Chunk* m_chunks = nullptr;

		public:
			int size;
			int componentsCountPerChunk;
			int chunkCount;

			ComponentDataStore(int _size);

			void Dispose() override;
			uint8_t* GetComponentDataPtr(int _index);
			void ResizeCapacity(int capacity);
		};

		struct Data
		{
			int capacity;
			int nextFreeIndex;
			int componentCount;
			int* versions;
			ComponentDataStore* components;
		};

		const int m_chunkSize = 32768;

		Data* m_data;

		void SetNextFreeIndex(ComponentDataStore* _ptr, int _index, int _value);
		int GetNextFreeIndex(ComponentDataStore* _ptr, int _index);

		void IncreaseCapacity();
		void ResizeCapacity(int _capacity);
		static void* ResizeArray(void* _fromPtr, long _fromCount, long _toCount, long _size, int _align);

	public:
		bool IsValid();
		int Capacity();

		LayoutDataStore(std::span<const ComponentType> _components, int initialCapacity);

		void Dispose() override;
		bool Exists(const LayoutHandle& _handle);

		const void* GetComponentDataPtr(int _index, int _componentIndex) const;
		LayoutHandle Allocate(uint8_t** _data, int _count);
		void Free(const LayoutHandle& _handle);

		template <typename T0>
		LayoutHandle Allocate(const T0& _comp0)
		{
			const T0* ptr2 = &_comp0;

			uint8_t* ptrs[1]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);

			return Allocate(ptrs, 1);
		}

		template <typename T0, typename T1>
		LayoutHandle Allocate(const T0& _comp0, const T1& _comp1)
		{
			const T0* ptr2 = &_comp0;
			const T1* ptr3 = &_comp1;

			uint8_t* ptrs[2]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);
			ptrs[1] = reinterpret_cast<const uint8_t*>(ptr3);

			return Allocate(ptrs, 2);
		}

		template <typename T0, typename T1, typename T2>
		LayoutHandle Allocate(const T0& _comp0, const T1& _comp1, const T2& _comp2)
		{
			const T0* ptr2 = &_comp0;
			const T1* ptr3 = &_comp1;
			const T2* ptr4 = &_comp2;

			uint8_t* ptrs[3]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);
			ptrs[1] = reinterpret_cast<const uint8_t*>(ptr3);
			ptrs[2] = reinterpret_cast<const uint8_t*>(ptr4);

			return Allocate(ptrs, 3);
		}

		template <typename T0, typename T1, typename T2, typename T3>
		LayoutHandle Allocate(const T0& _comp0, const T1& _comp1, const T2& _comp2, const T3& _comp3)
		{
			const T0* ptr2 = &_comp0;
			const T1* ptr3 = &_comp1;
			const T2* ptr4 = &_comp2;
			const T3* ptr5 = &_comp3;

			uint8_t* ptrs[4]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);
			ptrs[1] = reinterpret_cast<const uint8_t*>(ptr3);
			ptrs[2] = reinterpret_cast<const uint8_t*>(ptr4);
			ptrs[3] = reinterpret_cast<const uint8_t*>(ptr5);

			return Allocate(ptrs, 4);
		}

		template <typename T0, typename T1, typename T2, typename T3, typename T4>
		LayoutHandle Allocate(const T0& _comp0, const T1& _comp1, const T2& _comp2, const T3& _comp3, const T4& _comp4)
		{
			const T0* ptr2 = &_comp0;
			const T1* ptr3 = &_comp1;
			const T2* ptr4 = &_comp2;
			const T3* ptr5 = &_comp3;
			const T4* ptr6 = &_comp4;

			uint8_t* ptrs[5]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);
			ptrs[1] = reinterpret_cast<const uint8_t*>(ptr3);
			ptrs[2] = reinterpret_cast<const uint8_t*>(ptr4);
			ptrs[3] = reinterpret_cast<const uint8_t*>(ptr5);
			ptrs[4] = reinterpret_cast<const uint8_t*>(ptr6);

			return Allocate(ptrs, 5);
		}

		template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
		LayoutHandle Allocate(const T0& _comp0, const T1& _comp1, const T2& _comp2, const T3& _comp3, const T4& _comp4, const T5& _comp5)
		{
			const T0* ptr2 = &_comp0;
			const T1* ptr3 = &_comp1;
			const T2* ptr4 = &_comp2;
			const T3* ptr5 = &_comp3;
			const T4* ptr6 = &_comp4;
			const T5* ptr7 = &_comp5;

			uint8_t* ptrs[6]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);
			ptrs[1] = reinterpret_cast<const uint8_t*>(ptr3);
			ptrs[2] = reinterpret_cast<const uint8_t*>(ptr4);
			ptrs[3] = reinterpret_cast<const uint8_t*>(ptr5);
			ptrs[4] = reinterpret_cast<const uint8_t*>(ptr6);
			ptrs[5] = reinterpret_cast<const uint8_t*>(ptr7);

			return Allocate(ptrs, 6);
		}

		template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		LayoutHandle Allocate(const T0& _comp0, const T1& _comp1, const T2& _comp2, const T3& _comp3, const T4& _comp4, const T5& _comp5, const T6& _comp6)
		{
			const T0* ptr2 = &_comp0;
			const T1* ptr3 = &_comp1;
			const T2* ptr4 = &_comp2;
			const T3* ptr5 = &_comp3;
			const T4* ptr6 = &_comp4;
			const T5* ptr7 = &_comp5;
			const T6* ptr8 = &_comp6;

			uint8_t* ptrs[7]{};
			ptrs[0] = reinterpret_cast<const uint8_t*>(ptr2);
			ptrs[1] = reinterpret_cast<const uint8_t*>(ptr3);
			ptrs[2] = reinterpret_cast<const uint8_t*>(ptr4);
			ptrs[3] = reinterpret_cast<const uint8_t*>(ptr5);
			ptrs[4] = reinterpret_cast<const uint8_t*>(ptr6);
			ptrs[5] = reinterpret_cast<const uint8_t*>(ptr7);
			ptrs[6] = reinterpret_cast<const uint8_t*>(ptr8);

			return Allocate(ptrs, 7);
		}
	};
}