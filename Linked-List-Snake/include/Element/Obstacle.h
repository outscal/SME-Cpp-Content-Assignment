#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"

namespace Element
{
    class Obstacle
    {
    private:
        UI::UIElement::ImageView* obstacle_image;

        sf::Vector2i grid_position;

        float cell_width;
        float cell_height;

        void initializeObstacleImage();
        sf::Vector2f getObstacleImagePosition();

    public:
        Obstacle();
        ~Obstacle();

        void initialize(sf::Vector2i grid_pos, float width, float height);
        void update();
        void render();

        sf::Vector2i getObstaclePosition();
    };
}