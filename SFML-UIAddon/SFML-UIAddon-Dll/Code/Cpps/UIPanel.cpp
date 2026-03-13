#include "../Headers/SFUIL/UIPanel.hpp"
#include "../Headers/SFUIL/Containers/UIVisualContainer.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

SFUIL_API const char* SFUIL_PANEL_ROOTELEMENT_NAME = "__ROOT_ELEMENT__";

namespace sfui
{
	UIPanel::UIPanel()
	{
		m_size = sf::Vector2u(640, 360);
		m_renderTexture = sf::RenderTexture(m_size);

		m_rootElement = new UIVisualContainer(SFUIL_PANEL_ROOTELEMENT_NAME);
		m_rootElement->getProperty<PositionProperty>().setMode(PositionProperty::Mode::Absolute);
		SizeProperty& rootSize = m_rootElement->getProperty<SizeProperty>();
		rootSize.setWidth(100.f, SizeProperty::SizeType::Percentage);
		rootSize.setHeight(100.f, SizeProperty::SizeType::Percentage);
	}

	UIPanel::~UIPanel()
	{
		delete m_rootElement;
	}

	void UIPanel::render()
	{
		if (!m_active)
		{
			return;
		}

		m_renderTexture.clear(m_panelBackgroundColor);

		m_rootElement->drawToTarget(m_renderTexture);

		m_renderTexture.display();
	}

	void UIPanel::drawToTarget(sf::RenderTarget& _target)
	{
		if (!m_active)
		{
			return;
		}

		const sf::Texture& texture = m_renderTexture.getTexture();
		sf::Sprite sprite(texture);

		sf::Vector2f targetSize = sf::Vector2f(_target.getSize());
		sf::Vector2f position = Alignments::PositionFromAlignment(m_alignment, sf::Vector2f(targetSize), sf::Vector2f(m_size));
		sprite.setPosition(position + m_offset);

		_target.draw(sprite);
	}

	void UIPanel::setActive(bool _active)
	{
		m_active = _active;
	}

	const bool& UIPanel::isActive() const noexcept
	{
		return m_active;
	}

	void UIPanel::setSize(const sf::Vector2u& _size)
	{
		m_size = _size;
		static_cast<void>(m_renderTexture.resize(m_size));
	}

	void UIPanel::setSize(unsigned int _width, unsigned int _height)
	{
		setSize(sf::Vector2u(_width, _height));
	}

	const sf::Vector2u& UIPanel::getSize() const noexcept
	{
		return m_size;
	}

	const unsigned int& UIPanel::getWidth() const noexcept
	{
		return m_size.x;
	}

	const unsigned int& UIPanel::getHeight() const noexcept
	{
		return m_size.y;
	}

	void UIPanel::setAlignment(const Alignment _alignment)
	{
		m_alignment = _alignment;
	}

	const Alignment& UIPanel::getAlignment() const noexcept
	{
		return m_alignment;
	}

	void UIPanel::setOffset(const sf::Vector2f& _offset)
	{
		m_offset = _offset;
	}

	void UIPanel::setOffset(float _offsetX, float _offsetY)
	{
		setOffset({ _offsetX, _offsetY });
	}

	const sf::Vector2f& UIPanel::getOffset() const noexcept
	{
		return m_offset;
	}

	void UIPanel::setPanelBackgroundColor(const sf::Color& _color)
	{
		m_panelBackgroundColor = _color;
	}

	const sf::Color& UIPanel::getPanelBackgroundColor() const noexcept
	{
		return m_panelBackgroundColor;
	}

	UIVisualContainer* UIPanel::getRootElement() const noexcept
	{
		return m_rootElement;
	}

	void UIPanel::setRootElement(UIVisualContainer* _element)
	{
		if (m_rootElement != nullptr)
		{
			delete m_rootElement;
		}
		m_rootElement = _element;

		_element->AttachToPanel(this);
	}

	sf::Texture* UIPanel::getOrRegisterTexture(std::string _path)
	{
		if (_path.empty())
		{
			std::cerr << "Attempted to register texture with empty path." << std::endl;
			return nullptr;
		}

		if (m_textureCache.empty())
		{
			sf::Texture* texture = new sf::Texture();
			if (!texture->loadFromFile(_path))
			{
				std::cerr << "Failed to load texture from file: " << _path << std::endl;
				delete texture;
				return nullptr;
			}
			m_textureCache[_path] = std::make_pair(texture, 1);
			return m_textureCache[_path].first;
		}

		if (m_textureCache.contains(_path))
		{
			m_textureCache[_path].second++;
			return m_textureCache[_path].first;
		}
		else
		{
			sf::Texture* texture = new sf::Texture();
			if (!texture->loadFromFile(_path))
			{
				std::cerr << "Failed to load texture from file: " << _path << std::endl;
				delete texture;
				return nullptr;
			}
			m_textureCache[_path] = std::make_pair(texture, 1);
			return m_textureCache[_path].first;
		}
	}

	bool UIPanel::unregisterTexture(std::string _path)
	{
		if (_path.empty())
		{
			std::cerr << "Attempted to unregister texture with empty path." << std::endl;
			return false;
		}

		if (m_textureCache.contains(_path))
		{
			if (m_textureCache[_path].second > 0)
			{
				m_textureCache[_path].second--;
				if (m_textureCache[_path].second == 0)
				{
					m_textureCache.erase(_path);
				}
				return true;
			}
			else
			{
				std::cerr << "Attempted to unregister texture that has no references: " << _path << std::endl;
				return false;
			}
		}
		else
		{
			std::cerr << "Attempted to unregister texture that is not registered: " << _path << std::endl;
			return false;
		}
	}
}
