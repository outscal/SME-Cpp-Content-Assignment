#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"
#include "Direction.h"

namespace Player
{
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;
		Direction previous_direction;

		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();
		void initializeBodyPartImage();
		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();

		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionRight();

		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void updatePosition();
		void render();

		Direction getDirection();
		Direction getPreviousDirection();
		void setDirection(Direction direction);
		sf::Vector2i getPosition();
		void setPosition(sf::Vector2i position);

		sf::Vector2i getNextPosition();
		sf::Vector2i getPrevPosition();

	};
}