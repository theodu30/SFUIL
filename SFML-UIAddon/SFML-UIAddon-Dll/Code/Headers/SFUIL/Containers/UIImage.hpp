#pragma once

#include "../System/Exports.hpp"
#include "UIVisualContainer.hpp"

namespace sfui
{
	class SFUIL_API UIImage : public UIVisualContainer
	{
	public:
		UIImage();

		UIImage(const char* _name);

		~UIImage() override;

		void drawToTarget(sf::RenderTexture& _target) override;

		template<UIElementProperty T>
		T& getProperty()
		{
			markDirty();
			if constexpr (std::is_same_v<T, ImageProperty>)
			{
				return m_image;
			}
			else
			{
				return UIElement::getProperty<T>();
			}
		}

		template<UIElementProperty T>
		const T& getConstProperty() const
		{
			if constexpr (std::is_same_v<T, ImageProperty>)
			{
				return m_image;
			}
			else
			{
				return UIElement::getConstProperty<T>();
			}
		}

	protected:
		void reRenderIfDirty(sf::RenderTexture& _texture) override;

		void Initialize() override;

	private:
		ImageProperty m_image;

		void renderImage(sf::RenderTexture& _texture, sf::Vector2f _targetSize);
	};
}