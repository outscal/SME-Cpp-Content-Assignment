#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"

namespace Food
{
    enum class FoodType;

    class FoodItem
    {
    private:
        UI::UIElement::ImageView* food_image;

        sf::Vector2i grid_position;

        float cell_width;
        float cell_height;

        FoodType food_type;

        void initializeFoodImage();
        sf::String getFoodTexturePath();
        sf::Vector2f getFoodImagePosition();

    public:
        static const int number_of_foods = 8;
        static const int number_of_healthy_foods = 4;

        FoodItem();
        ~FoodItem();

        void initialize(sf::Vector2i grid_pos, float width, float height, FoodType type);
        void update();
        void render();

        FoodType getFoodType();
        sf::Vector2i getFoodPosition();
    };
}