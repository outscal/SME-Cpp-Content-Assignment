#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const sf::String outscal_logo_texture_path;
		static const sf::String background_texture_path;
		static const sf::String obstacle_texture_path;
		static const sf::String snake_body_texture_path;

		static const sf::String apple_texture_path;
		static const sf::String mango_texture_path;
		static const sf::String orange_texture_path;
		static const sf::String pizza_texture_path;
		static const sf::String burger_texture_path;
		static const sf::String cheese_texture_path;
		static const sf::String poision_texture_path;
		static const sf::String alcohol_texture_path;

		static const sf::String play_button_texture_path;
		static const sf::String instructions_button_texture_path;
		static const sf::String quit_button_texture_path;
		static const sf::String menu_button_texture_path;
		static const sf::String level_one_button_texture_path;
		static const sf::String level_two_button_texture_path;
		static const sf::String single_linked_list_button_texture_path;
		static const sf::String double_linked_list_button_texture_path;

		static const sf::String bubble_bobble_font_path;
		static const sf::String DS_DIGIB_font_path;

		static const sf::String background_music_path;
		static const sf::String button_click_sound_path;
		static const sf::String pickup_sound_path;
		static const sf::String death_sound_path;
	};
}