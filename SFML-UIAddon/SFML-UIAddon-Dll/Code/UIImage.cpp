#include "Headers/SFUIL/Containers/UIImage.hpp"

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

			float posX = m_image.getPositionX().resolveToPixels(imageWidth);
			float posY = m_image.getPositionY().resolveToPixels(imageHeight);
			
			sf::Vector2f renderPos = getRenderPosition() + sf::Vector2f(posX, posY);
			
			sf::Vector2f renderScale;
			float xScale = imageWidth / static_cast<float>(img.getSize().x);
			float yScale = imageHeight / static_cast<float>(img.getSize().y);
			
			switch (m_image.getScaleMode())
			{
			case ImageProperty::ScaleMode::StretchToFill:
				renderScale = { xScale, yScale };
				break;
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

			sf::Transform local;

			local.translate(renderPos);
			local.scale(renderScale);

			sf::Transform world = getConstProperty<TransformProperty>().getWorldTransform(this);

			local = world * local;

			sprite.setPosition(local.transformPoint({ 0.f, 0.f }));
			const float* m = local.getMatrix();
			float angleRad = std::atan2(m[1], m[0]);
			sprite.setRotation(sf::radians(angleRad));
			sprite.setScale({ std::sqrt(m[0] * m[0] + m[1] * m[1]), std::sqrt(m[4] * m[4] + m[5] * m[5]) });

			_texture.draw(sprite);
		}
	}

}
