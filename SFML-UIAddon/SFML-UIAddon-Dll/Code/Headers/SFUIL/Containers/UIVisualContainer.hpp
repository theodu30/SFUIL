#pragma once

#include "../System/Exports.hpp"
#include "../UIElement.hpp"

extern SFUIL_API const char* SFUIL_UIVISUALCONTAINER_NAME;

namespace sfui
{
	class SFUIL_API UIVisualContainer : public UIElement
	{
	public:
		virtual const char* getTypeName() const override { return SFUIL_UIVISUALCONTAINER_NAME; }
		static const char* staticTypeName() { return SFUIL_UIVISUALCONTAINER_NAME; }

		UIVisualContainer();

		UIVisualContainer(const char* _name);

		~UIVisualContainer();

		void drawToTarget(sf::RenderTexture& _target) override;

		virtual void calculateContentSize(sf::Vector2u& _contentSize) const;

	protected:
		void reRenderIfDirty(sf::RenderTexture& _texture) override;

		void Initialize() override;

	private:
		void calculateNewSize(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		void calculateNewSizeInAbsolute(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		void calculateNewSizeInRelative(sf::Vector2u& newSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex);

		void calculateFinalMinMaxSizes(sf::Vector2u& minSize, sf::Vector2u& maxSize, const sf::Vector2u& _parentSize, const FlexProperty& _parentFlex) const;

		float resolveFinalBasicWidth(const UIVisualContainer& _child, const float& _parentWidth) const;

		float resolveFinalBasicHeight(const UIVisualContainer& _child, const float& _parentHeight) const;
	};
}