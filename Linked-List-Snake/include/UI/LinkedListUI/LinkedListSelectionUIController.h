#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"

namespace UI
{
	namespace LinkedListUI
	{
		class LinkedListSelectionUIController : public Interface::IUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float single_linked_list_button_y_position = 500.f;
			const float double_linked_list_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			const float background_alpha = 85.f;

			UIElement::ImageView* background_image;

			UIElement::ButtonView* single_linked_list_button;
			UIElement::ButtonView* double_linked_list_button;
			UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();
			float calculateLeftOffsetForButton();

			void singleLinkedListButtonCallback();
			void doubleLinkedListButtonCallback();
			void menuButtonCallback();

			void destroy();

		public:
			LinkedListSelectionUIController();
			~LinkedListSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}