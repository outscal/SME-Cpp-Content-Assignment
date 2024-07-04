#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		enum class UIState
		{
			VISIBLE,
			HIDDEN,
		};

		class UIView
		{
		protected:
			sf::RenderWindow* game_window;
			UIState ui_state;

		public:
			UIView();
			virtual ~UIView();

			virtual void initialize();
			virtual void update();
			virtual void render();

			virtual void show();
			virtual void hide();
		};
	}
}