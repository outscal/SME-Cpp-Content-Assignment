#include "UI/MainMenu/MainMenuUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        MainMenuUIController::MainMenuUIController()
        {
            createImage();
            createButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void MainMenuUIController::createImage()
        {
            background_image = new ImageView();
        }

        void MainMenuUIController::createButtons()
        {
            play_button = new ButtonView();
            instructions_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void MainMenuUIController::initializeButtons()
        {
            play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
            instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

            play_button->setCentreAlinged();
            instructions_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void MainMenuUIController::registerButtonCallback()
        {
            play_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
            instructions_button->registerCallbackFuntion(std::bind(&MainMenuUIController::instructionsButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::LEVEL_SELECTION);
        }

        void MainMenuUIController::instructionsButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::INSTRUCTIONS);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void MainMenuUIController::update()
        {
            background_image->update();
            play_button->update();
            instructions_button->update();
            quit_button->update();
        }

        void MainMenuUIController::render()
        {
            background_image->render();
            play_button->render();
            instructions_button->render();
            quit_button->render();
        }

        void MainMenuUIController::show()
        {
            background_image->show();
            play_button->show();
            instructions_button->show();
            quit_button->show();
        }

        void MainMenuUIController::destroy()
        {
            delete (play_button);
            delete (instructions_button);
            delete (quit_button);
            delete (background_image);
        }
    }
}