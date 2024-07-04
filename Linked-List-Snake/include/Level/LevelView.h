#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/RectangleShapeView.h"

namespace Level
{
    class LevelView
    {
    private:
        const sf::Color background_color = sf::Color(180, 200, 160);
        const sf::Color border_color = sf::Color::Black;

        UI::UIElement::RectangleShapeView* background_rectangle;
        UI::UIElement::RectangleShapeView* border_rectangle;

        float grid_width;
        float grid_height;

        void createViews();
        void initializeBackground();
        void initializeBorder();
        void calculateGridExtents();
        void destroy();

    public:
        static const int border_thickness = 10;
        static const int border_offset_left = 40;
        static const int border_offset_top = 100;
        static const int border_offset_bottom = 40;

        LevelView();
        ~LevelView();

        void initialize();
        void update();
        void render();

        float getGridWidth();
        float getGridHeight();
    };
}