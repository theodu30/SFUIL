#pragma once

#include "System/Exports.hpp"
#include <vector>
#include <string>

namespace sfui
{
	enum class SFUIL_API PseudoStates : char
	{
		None = 0,
		Active = 1,
		Hover = 2,
		Checked = 8,
		Disabled = 0x20,
		Focus = 0x40,
		Root = 0x80
	};

	enum class SFUIL_API PickingMode : char
	{
		Position,
		Ignore
	};

	class SFUIL_API UIVisualElement
	{
	private:
		std::string m_name;

		int m_hierarchyDepth;
		int m_insertionIndex = -1;

		PseudoStates m_pseudoStates;
		PickingMode m_pickingMode;

	public:
		class Hierarchy
		{
		private:
			UIVisualElement* m_owner = nullptr;

			std::vector<UIVisualElement*> GetChildren();
			Hierarchy(UIVisualElement* _element);
			void BringToFront(UIVisualElement* _child);
			void SendToBack(UIVisualElement* _child);
			void PlaceBehind(UIVisualElement* _child, UIVisualElement* _over);
			void PlaceInFront(UIVisualElement* _child, UIVisualElement* _under);
			void MoveChildElement(UIVisualElement* _child, int _currentIndex, int _nextIndex);
			void SetParent(UIVisualElement* _value);
			void PutChildAtIndex(UIVisualElement* _child, int _index);
			void RemoveChildAtIndex(int _index);

		public:
			UIVisualElement* GetParent();
			size_t GetChildCount();

			UIVisualElement* operator[](int _index);
			bool operator==(Hierarchy _other);
			bool operator!=(Hierarchy _other);

			void Add(UIVisualElement* _child);
			void Insert(int _index, UIVisualElement* _child);
			void Remove(UIVisualElement* _child);
			void RemoveAt(int _index);
			void Clear();
			size_t IndexOf(UIVisualElement* _child);
			UIVisualElement* ElementAt(int _index);
			std::vector<UIVisualElement*> Children();
		};
	};
}