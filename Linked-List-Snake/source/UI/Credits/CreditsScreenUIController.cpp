#include "UI/Credits/CreditsScreenUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"

namespace UI
{
    namespace Credits
    {
        using namespace Global;
        using namespace Event;
        using namespace Sound;
        using namespace Main;
        using namespace UI::UIElement;

        CreditsScreenUIController::CreditsScreenUIController()
        {
            createText();
            createImage();
            createButtons();
        }

        CreditsScreenUIController::~CreditsScreenUIController()
        {
            destroy();
        }

        void CreditsScreenUIController::initialize()
        {
            initializeText();
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void CreditsScreenUIController::createText()
        {
            title_text = new TextView();
        }

        void CreditsScreenUIController::createImage()
        {
            background_image = new ImageView();
        }

        void CreditsScreenUIController::createButtons()
        {
            menu_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void CreditsScreenUIController::initializeText()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            float x_position = (game_window->getSize().x - calculateTextWidth(game_title)) / 2;

            title_text->initialize(game_title, sf::Vector2f(x_position, text_top_offset), FontType::BUBBLE_BOBBLE, font_size, text_color);
        }

        void CreditsScreenUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void CreditsScreenUIController::initializeButtons()
        {
            float x_position = calculateLeftOffsetForButton();

            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_position, menu_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(x_position, quit_button_y_position));
        }

        void CreditsScreenUIController::registerButtonCallback()
        {
            menu_button->registerCallbackFuntion(std::bind(&CreditsScreenUIController::menuButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&CreditsScreenUIController::quitButtonCallback, this));
        }

        void CreditsScreenUIController::menuButtonCallback()
        {
            // GameState will change to gameplay state.
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void CreditsScreenUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void CreditsScreenUIController::update()
        {
            background_image->update();
            menu_button->update();
            quit_button->update();
            title_text->update();
        }

        void CreditsScreenUIController::render()
        {
            background_image->render();
            menu_button->render();
            quit_button->render();
            title_text->render();
        }

        void CreditsScreenUIController::show()
        {
            background_image->show();
            menu_button->show();
            quit_button->show();
            title_text->show();
        }

        void CreditsScreenUIController::destroy()
        {
            delete (title_text);
            delete (menu_button);
            delete (quit_button);
            delete (background_image);
        }

        float CreditsScreenUIController::calculateLeftOffsetForButton()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
        }

        float CreditsScreenUIController::calculateTextWidth(sf::String text_value)
        {
            sf::Text text;
            sf::Font font;
            if (!font.loadFromFile(Config::bubble_bobble_font_path)) return 0;

            text.setFont(font);
            text.setString(text_value);
            text.setCharacterSize(font_size);

            return text.getLocalBounds().width;
        }
    }
}