#pragma once

#include "System/Exports.hpp"
#include "System/PanelAnchor.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <map>

extern SFUIL_API const char* SFUIL_PANEL_ROOTELEMENT_NAME;

namespace sfui
{
	class UIVisualContainer;

	class SFUIL_API UIPanel
	{
	public:
		UIPanel();
		~UIPanel();

		void render();

		void drawToTarget(sf::RenderTarget& _target);

		void setActive(bool _active);
		const bool& isActive() const noexcept;

		void setSize(const sf::Vector2u& _size);
		void setSize(unsigned int _width, unsigned int _height);
		[[nodiscard]] const sf::Vector2u& getSize() const noexcept;
		const unsigned int& getWidth() const noexcept;
		const unsigned int& getHeight() const noexcept;

		void setAlignment(const Alignment _alignment);
		[[nodiscard]] const Alignment& getAlignment() const noexcept;

		void setOffset(const sf::Vector2f& _offset);
		void setOffset(float _offsetX, float _offsetY);
		[[nodiscard]] const sf::Vector2f& getOffset() const noexcept;

		void setPanelBackgroundColor(const sf::Color& _color);
		[[nodiscard]] const sf::Color& getPanelBackgroundColor() const noexcept;

		UIVisualContainer* getRootElement() const noexcept;
		void setRootElement(UIVisualContainer* _element);

		sf::Texture* getOrRegisterTexture(std::string _path);
		bool unregisterTexture(std::string _path);

	private:
		bool m_active = false;
		Alignment m_alignment;
		sf::Color m_panelBackgroundColor = sf::Color::Transparent;
		sf::Vector2u m_size;
		sf::Vector2f m_offset = sf::Vector2f();
		sf::RenderTexture m_renderTexture;
		UIVisualContainer* m_rootElement = nullptr;

		std::map<std::string, std::pair<sf::Texture*, unsigned int>> m_textureCache;
	};
}