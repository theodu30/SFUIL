#pragma once

#include "Property.hpp"

namespace sfui
{
	class SFUIL_API SizeProperty : public Property
	{
	public:
		void exportToXML(std::ostream& _stream) const override;

		enum class SizeType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct SizeValue
		{
			float value = 0.f;
			SizeType type = SizeType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		struct Size
		{
			SizeValue width;
			bool widthDirty = false;
			SizeValue height;
			bool heightDirty = false;
		};

		[[nodiscard]] const Size& getSize() const;
		void setSize(const Size& _size);
		void setWidth(float _value, SizeType _type);
		void setWidth(float _value);
		void setHeight(float _value, SizeType _type);
		void setHeight(float _value);
		void resetSize();
		void resetWidth();
		void resetHeight();

		enum class MinSizeType : char
		{
			Auto,
			Pixels,
			Percentage
		};

		struct MinSizeValue
		{
			float value = 0.f;
			MinSizeType type = MinSizeType::Auto;

			float resolveToPixels(float _relativeTo) const;
		};

		struct MinSize
		{
			MinSizeValue width;
			bool widthDirty = false;
			MinSizeValue height;
			bool heightDirty = false;
		};

		[[nodiscard]] const MinSize& getMinSize() const;
		void setMinSize(const MinSize& _minSize);
		void setMinWidth(float _value, MinSizeType _type);
		void setMinWidth(float _value);
		void setMinHeight(float _value, MinSizeType _type);
		void setMinHeight(float _value);
		void resetMinSize();
		void resetMinWidth();
		void resetMinHeight();

		enum class MaxSizeType : char
		{
			None,
			Pixels,
			Percentage
		};

		struct MaxSizeValue
		{
			float value = 0.f;
			MaxSizeType type = MaxSizeType::None;

			float resolveToPixels(float _relativeTo) const;
		};

		struct MaxSize
		{
			MaxSizeValue width;
			bool widthDirty = false;
			MaxSizeValue height;
			bool heightDirty = false;
		};

		[[nodiscard]] const MaxSize& getMaxSize() const;
		void setMaxSize(const MaxSize& _maxSize);
		void setMaxWidth(float _value, MaxSizeType _type);
		void setMaxWidth(float _value);
		void setMaxHeight(float _value, MaxSizeType _type);
		void setMaxHeight(float _value);
		void resetMaxSize();
		void resetMaxWidth();
		void resetMaxHeight();

	private:
		Size m_size;
		MinSize m_minSize;
		MaxSize m_maxSize;
	};
}