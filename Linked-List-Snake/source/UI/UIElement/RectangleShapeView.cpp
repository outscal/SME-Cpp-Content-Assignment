#include "UI/UIElement/RectangleShapeView.h"

namespace UI
{
	namespace UIElement
	{
		RectangleShapeView::RectangleShapeView() = default;

		RectangleShapeView::~RectangleShapeView() = default;

		void RectangleShapeView::initialize(sf::Vector2f rectangle_size, sf::Vector2f rectangle_position, int outline_thickness, sf::Color fill_color, sf::Color outline_color)
		{
			UIView::initialize();

			setSize(rectangle_size);
			setPosition(rectangle_position);
			setOutlineThickness(outline_thickness);
			setFillColor(fill_color);
			setOutlineColor(outline_color);
		}

		void RectangleShapeView::update()
		{
			UIView::update();
		}

		void RectangleShapeView::render()
		{
			UIView::render();

			if (ui_state == UIState::VISIBLE)
			{
				game_window->draw(rectangle_shape);
			}
		}

		void RectangleShapeView::setSize(sf::Vector2f rectangle_size)
		{
			rectangle_shape.setSize(rectangle_size);
		}

		void RectangleShapeView::setPosition(sf::Vector2f rectangle_position)
		{
			rectangle_shape.setPosition(rectangle_position);
		}

		void RectangleShapeView::setFillColor(sf::Color fill_color)
		{
			rectangle_shape.setFillColor(fill_color);
		}

		void RectangleShapeView::setOutlineColor(sf::Color outline_color)
		{
			rectangle_shape.setOutlineColor(outline_color);
		}

		void RectangleShapeView::setOutlineThickness(int outline_thickness)
		{
			rectangle_shape.setOutlineThickness(outline_thickness);
		}

	}
}