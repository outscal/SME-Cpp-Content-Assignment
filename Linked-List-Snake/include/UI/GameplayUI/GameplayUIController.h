#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float font_size = 60.f;

			const float text_y_position = 7.f;
			const float level_number_text_x_position = 65.f;
			const float score_text_x_position = 800.f;

			// Constants: Operations and Time Complexities
			const float operations_font_size = 36.f;
			const float operations_text_x_position = 1330.f;
			const float operations_text_y_position = 10.f;
			const float time_complexity_text_x_position = 1330.f;
			const float time_complexity_text_y_position = 45.f;

			UI::UIElement::TextView* level_number_text;
			UI::UIElement::TextView* score_text;
			UI::UIElement::TextView* time_complexity_text;
			UI::UIElement::TextView* operation_text;

			void createTexts();
			void initializeTexts();
			void initializeLevelNumberText();
			void initializeScoreText();
			void initializeTimeComplexityText();
			void initializeOperationText();

			void updateLevelNumberText();
			void updateScoreText();
			void updateTimeComplexityText();
			void updateOperationText();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}

