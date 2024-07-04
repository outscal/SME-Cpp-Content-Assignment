#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Interface/IUIController.h"
#include "UI//UIElement/ButtonView.h"
#include "UI//UIElement/ImageView.h"
#include "UI//UIElement/TextView.h"

namespace UI
{
	namespace Instructions
	{
		class InstructionsScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float menu_button_y_position = 800.f;
			const float background_alpha = 85.f;

			static const int number_of_instructions = 7;
			const float top_offset = 105.f;
			const float text_spacing = 95.f;
			const int font_size = 55;

			const sf::Color text_color = sf::Color(0, 200, 0);

			sf::String instructions[number_of_instructions] = { "Choose your snake type: 'Single' or 'Double' Linked List.",
																"Control the snake using arrow keys.",
																"Each 'Food' type will trigger unique linked list operation.",
																"Avoid collisions with obstacles and yourself.",
																"Time complexity displayed in the UI",
																"Survive for the highest score." };

			UIElement::ImageView* background_image;
			UIElement::ButtonView* menu_button;

			std::vector<UIElement::TextView*> instructions_text_list;

			void createImage();
			void createButtons();
			void createText();
			void initializeBackgroundImage();
			void initializeButtons();
			void initializeTexts();
			void registerButtonCallback();
			float calculateLeftOffsetForButton();

			void menuButtonCallback();

			void destroy();

		public:
			InstructionsScreenUIController();
			~InstructionsScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}