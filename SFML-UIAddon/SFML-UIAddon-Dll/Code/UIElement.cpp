#include "Headers/SFUIL/UIElement.hpp"
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Headers/SFUIL/Graphics/RoundedRectangle.hpp"

SFUIL_API const char* SFUIL_UIELEMENT_NAME = "UIElement";

namespace sfui
{
	UIElement::UIElement(const char* _name) : m_name(_name)
	{
	}

	void UIElement::setName(const char* _name)
	{
		m_name = _name;
	}

	const char* UIElement::getName() const
	{
		return m_name;
	}

	size_t UIElement::getChildCount() const noexcept
	{
		return m_children.size();
	}

	bool UIElement::addChild(UIElement* _child)
	{
		if (_child == nullptr)
		{
			return false;
		}
		_child->m_parent = this;
		m_children.push_back(_child);
		return true;
	}

	bool UIElement::removeFromParent()
	{
		if (m_parent)
		{
			auto& siblings = m_parent->m_children;
			auto it = std::find(siblings.begin(), siblings.end(), this);
			if (it != siblings.end())
			{
				siblings.erase(it);
				m_parent = nullptr;
				return true;
			}
		}
		return false;
	}

	bool UIElement::removeFromHierarchy()
	{
		// Remove from parent first if exists
		if (m_parent)
		{
			m_parent->removeFromParent();
		}
		// Recursively remove all children
		for (auto& child : m_children)
		{
			child->removeFromHierarchy();
		}
		m_children.clear();
		return true;
	}

	std::vector<UIElement*>& UIElement::getChildren()
	{
		return m_children;
	}

	const UIElement* UIElement::getParent() const
	{
		return m_parent;
	}

	sf::Vector2f UIElement::getRenderSize() const
	{
		return m_renderSize;
	}

	sf::Vector2f UIElement::getRenderPosition() const
	{
		return m_renderPosition;
	}

	void UIElement::markDirty()
	{
		m_dirty = true;
		if (m_parent)
		{
			m_parent->markDirty();
		}
	}

	void UIElement::computePosition(const sf::Vector2f& _targetSize, const sf::FloatRect& _bounds)
	{
		float posX = 0.f;
		float posY = 0.f;
		if (UIPropUtils::isPositionAbsolute(m_position))
		{
			if (m_position.getLeft().type != PositionProperty::ValueType::Auto)
			{
				posX = m_position.getLeft().resolveToPixels(_targetSize.x);
			}
			else if (m_position.getRight().type != PositionProperty::ValueType::Auto)
			{
				float rightPos = m_position.getRight().resolveToPixels(_targetSize.x);
				posX = _targetSize.x - rightPos - _bounds.size.x;
			}

			if (m_position.getTop().type != PositionProperty::ValueType::Auto)
			{
				posY = m_position.getTop().resolveToPixels(_targetSize.y);
			}
			else if (m_position.getBottom().type != PositionProperty::ValueType::Auto)
			{
				float bottomPos = m_position.getBottom().resolveToPixels(_targetSize.y);
				posY = _targetSize.y - bottomPos - _bounds.size.y;
			}
		}
		else if (UIPropUtils::isPositionRelative(m_position))
		{
			if (m_parent)
			{
				const AlignProperty& parentAlign = m_parent->getConstProperty<AlignProperty>();

				const FlexProperty& parentFlex = m_parent->getConstProperty<FlexProperty>();

				size_t siblingCount = m_parent->getChildCount();
				size_t trueSiblingCount = siblingCount;

				size_t siblingIndex = 0;
				size_t offsetIndex = 0;
				for (size_t i = 0; i < siblingCount; ++i)
				{
					if (m_parent->getChildren()[i] == this)
					{
						siblingIndex = i - offsetIndex;
					}
					else if (m_parent->getChildren()[i]->getConstProperty<DisplayProperty>().getDisplay() == DisplayProperty::Type::None)
					{
						--trueSiblingCount;
						++offsetIndex;
					}
					else if (UIPropUtils::isPositionAbsolute(m_parent->getChildren()[i]->getConstProperty<PositionProperty>()))
					{
						--trueSiblingCount;
						++offsetIndex;
					}
				}
				siblingCount = trueSiblingCount;

				if (UIPropUtils::isFlexDirectionRowType(parentFlex))
				{
					posX = UIPropUtils::calculateJustifyContentOffset(parentAlign, siblingIndex, siblingCount, _bounds.size.x, _targetSize.x);
					posY = UIPropUtils::calculateAlignItemsOffset(parentAlign, _bounds.size.y, _targetSize.y);
				}
				else if (UIPropUtils::isFlexDirectionColumnType(parentFlex))
				{
					posY = UIPropUtils::calculateJustifyContentOffset(parentAlign, siblingIndex, siblingCount, _bounds.size.y, _targetSize.y);
					posX = UIPropUtils::calculateAlignItemsOffset(parentAlign, _bounds.size.x, _targetSize.x);
				}
			}
			else
			{
				posX = 0.f;
				posY = 0.f;
			}
		}

		m_renderPosition = sf::Vector2f(posX, posY);
	}

	void UIElement::computeTransformations(const sf::FloatRect& _bounds)
	{
		m_transform.setCalculatedOriginPixels(m_transform.getOrigin().toVector2f(_bounds.size.x, _bounds.size.y));

		m_transform.setCalculatedTranslatePixels(m_renderPosition + m_transform.getTranslate().toVector2f(_bounds.size.x, _bounds.size.y));

		m_transform.setCalculatedScale(m_transform.getScale().toVector2f());

		m_transform.setRotate(UIPropUtils::normalizedAngle(m_transform.getRotate()));
		m_transform.setCalculatedRotateAngle(m_transform.getRotate().resolveToSfAngle());
	}

	void UIElement::applyTransformations(const sf::Vector2f& _targetSize, sf::Sprite& _sprite)
	{
		// Compute transformations based on current bounds
		computeTransformations(_sprite.getGlobalBounds());

		// Apply world transform
		UIPropUtils::applyWorldTransform(_sprite, m_transform.getWorldTransform(this));
	}

	void UIElement::applyTransformations(const sf::Vector2f& _targetSize, sf::Shape& _shape)
	{
		// Compute transformations based on current bounds
		computeTransformations(_shape.getGlobalBounds());

		// Apply world transform
		UIPropUtils::applyWorldTransform(_shape, m_transform.getWorldTransform(this));
	}

	void UIElement::drawBackground(sf::RenderTexture& _target, const sf::Vector2f& _targetSize)
	{
		size_t pointsPerCorner = static_cast<size_t>(std::fmaxf(1.f, std::ceilf(m_border.getRadius())));
		float radius = m_border.getRadius();
		if (pointsPerCorner == 1 || radius == 0.f)
		{
			sf::RectangleShape backgroundShape;
			backgroundShape.setSize(m_renderSize);
			backgroundShape.setFillColor(m_background.getColor());
			backgroundShape.setOutlineThickness(-std::fabs(m_border.getWidth()));
			backgroundShape.setOutlineColor(m_border.getColor());

			computePosition(_targetSize, backgroundShape.getGlobalBounds());
			applyTransformations(_targetSize, backgroundShape);

			_target.draw(backgroundShape);
		}
		else
		{
			RoundedRectangle backgroundShape;
			backgroundShape.setSize(m_renderSize);
			backgroundShape.setFillColor(m_background.getColor());
			backgroundShape.setOutlineThickness(-std::fabs(m_border.getWidth()));
			backgroundShape.setOutlineColor(m_border.getColor());
			backgroundShape.setRadius(m_border.getRadius());
			backgroundShape.setPointsPerCorner(pointsPerCorner);

			computePosition(_targetSize, backgroundShape.getGlobalBounds());
			applyTransformations(_targetSize, backgroundShape);

			_target.draw(backgroundShape);
		}
	}
}