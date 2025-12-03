#include "Headers/SFUIL/Containers/UIImage.hpp"
#include <iostream>

namespace sfui
{
	UIImage::UIImage() : UIVisualContainer("UIImage")
	{
		Initialize();
	}

	UIImage::UIImage(const char* _name) : UIVisualContainer(_name)
	{
		Initialize();
	}

	UIImage::~UIImage()
	{
	}

	void UIImage::drawToTarget(sf::RenderTexture& _target)
	{
		if (m_display.getDisplay() == DisplayProperty::Type::None)
		{
			return;
		}

		reRenderIfDirty(_target);

		sf::Vector2f targetSize(_target.getSize());
		if (m_parent)
		{
			targetSize = m_parent->getRenderSize();
		}

		drawBackground(_target, targetSize);
		renderImage(_target, targetSize);

		for (auto& child : m_children)
		{
			child->drawToTarget(_target);
		}
	}

	void UIImage::reRenderIfDirty(sf::RenderTexture& _texture)
	{
		if (!m_dirty) return;

		// Call the base class implementation to handle common re-rendering tasks
		UIVisualContainer::reRenderIfDirty(_texture);
	}

	void UIImage::Initialize()
	{
		UIVisualContainer::Initialize();
		markDirty();
	}

	void UIImage::renderImage(sf::RenderTexture& _texture, sf::Vector2f _targetSize)
	{
		float imageWidth = m_image.getSize().width.resolveToPixels(_targetSize.x);
		float imageHeight = m_image.getSize().height.resolveToPixels(_targetSize.y);

		sf::Image img = m_image.getImage();
		sf::Texture texture;
		if (texture.loadFromImage(img))
		{
			texture.setRepeated(m_image.getRepeat() == ImageProperty::Repeat::Repeat);
			texture.setSmooth(m_image.getSmooth() == ImageProperty::Smooth::Smooth);

			sf::Sprite sprite(texture);
			sprite.setColor(m_image.getTintColor());

			sf::Vector2f renderScale;
			float xScale = imageWidth / static_cast<float>(img.getSize().x);
			float yScale = imageHeight / static_cast<float>(img.getSize().y);

			if (UIPropUtils::isPositionRelative(m_position))
			{
				xScale *= m_renderSize.x / _targetSize.x;
				yScale *= m_renderSize.y / _targetSize.y;
			}

			float relativeWidth = 0.f;
			float relativeHeight = 0.f;

			switch (m_image.getScaleMode())
			{
			case ImageProperty::ScaleMode::StretchToFill:
			{
				renderScale = { xScale, yScale };
				break;
			}
			case ImageProperty::ScaleMode::ScaleAndCrop:
			{
				float scale = std::max(xScale, yScale);
				renderScale = { scale, scale };
				break;
			}
			case ImageProperty::ScaleMode::ScaleToFit:
			{
				float scale = std::min(xScale, yScale);
				renderScale = { scale, scale };
				break;
			}
			}

			relativeWidth = m_renderSize.x * renderScale.x / xScale;
			relativeHeight = m_renderSize.y * renderScale.y / yScale;

			float originalScaleWidth = imageWidth / _targetSize.x;
			float originalScaleHeight = imageHeight / _targetSize.y;

			relativeWidth *= originalScaleWidth;
			relativeHeight *= originalScaleHeight;

			float posX = m_image.getPositionX().resolveToPixels(relativeWidth, m_renderSize.x);
			float posY = m_image.getPositionY().resolveToPixels(relativeHeight, m_renderSize.y);

			sf::Vector2f renderPosition = sf::Vector2f(posX, posY);

			sf::Transform local;

			local.translate(renderPosition);
			local.scale(renderScale);

			sf::Transform world = m_transform.getWorldTransform(this);

			local = world * local;

			UIPropUtils::applyWorldTransform(sprite, local);

			_texture.draw(sprite);
		}
	}
}
