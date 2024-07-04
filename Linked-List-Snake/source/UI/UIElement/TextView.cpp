#include "UI/UIElement/TextView.h"
#include "Global/Config.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;

		sf::Font TextView::font_bubble_bobble;
		sf::Font TextView::font_DS_DIGIB;

		TextView::TextView() = default;

		TextView::~TextView() = default;

		void TextView::initialize(sf::String text_value, sf::Vector2f position, FontType font_type, int font_size, sf::Color color)
		{
			UIView::initialize();

			setText(text_value);
			setTextPosition(position);
			setFont(font_type);
			setFontSize(font_size);
			setTextColor(color);
		}

		void TextView::update()
		{
			UIView::update();
		}

		void TextView::render()
		{
			UIView::render();

			if (ui_state == UIState::VISIBLE)
			{
				game_window->draw(text);
			}
		}

		void TextView::initializeTextView()
		{
			loadFont();
		}

		void TextView::loadFont()
		{
			font_bubble_bobble.loadFromFile(Config::bubble_bobble_font_path);
			font_DS_DIGIB.loadFromFile(Config::DS_DIGIB_font_path);
		}

		void TextView::setText(sf::String text_value)
		{
			text.setString(text_value);
		}

		void TextView::setFont(FontType font_type)
		{
			switch (font_type)
			{
			case FontType::BUBBLE_BOBBLE:
				text.setFont(font_bubble_bobble);
				break;
			case FontType::DS_DIGIB:
				text.setFont(font_DS_DIGIB);
				break;
			}
		}

		void TextView::setFontSize(int font_size)
		{
			text.setCharacterSize(font_size);
		}

		void TextView::setTextPosition(sf::Vector2f position)
		{
			text.setPosition(position);
		}

		void TextView::setTextColor(sf::Color color)
		{
			text.setFillColor(color);
		}

		void TextView::setTextCentreAligned()
		{
			float x_position = (game_window->getSize().x - text.getLocalBounds().width) / 2;
			float y_position = text.getGlobalBounds().getPosition().y;

			text.setPosition(sf::Vector2f(x_position, y_position));
		}
	}
}