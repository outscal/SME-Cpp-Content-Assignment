#include "UI/LinkedListUI/LinkedListSelectionUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"
#include "Level/LevelService.h"


namespace UI
{
    namespace LinkedListUI
    {
        using namespace Global;
        using namespace Event;
        using namespace Sound;
        using namespace Main;
        using namespace Graphics;
        using namespace Level;
        using namespace UI::UIElement;

        LinkedListSelectionUIController::LinkedListSelectionUIController()
        {
            createButtons();
            createImage();
        }

        LinkedListSelectionUIController::~LinkedListSelectionUIController()
        {
            destroy();
        }

        void LinkedListSelectionUIController::initialize()
        {
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void LinkedListSelectionUIController::createImage()
        {
            background_image = new ImageView();
        }

        void LinkedListSelectionUIController::createButtons()
        {
            single_linked_list_button = new ButtonView();
            double_linked_list_button = new ButtonView();
            menu_button = new ButtonView();
        }

        void LinkedListSelectionUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void LinkedListSelectionUIController::initializeButtons()
        {
            float x_position = calculateLeftOffsetForButton();

            single_linked_list_button->initialize("Single Linked List Button", Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_position, single_linked_list_button_y_position));
            double_linked_list_button->initialize("Double Linked List Button", Config::double_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_position, double_linked_list_button_y_position));
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_position, menu_button_y_position));
        }

        void LinkedListSelectionUIController::registerButtonCallback()
        {
            single_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::singleLinkedListButtonCallback, this));
            double_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::doubleLinkedListButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::menuButtonCallback, this));
        }

        float LinkedListSelectionUIController::calculateLeftOffsetForButton()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
        }

        void LinkedListSelectionUIController::singleLinkedListButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
            ServiceLocator::getInstance()->getLevelService()->createLevel(LinkedListType::SINGLE_LINKED_LIST);
        }

        void LinkedListSelectionUIController::doubleLinkedListButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
            ServiceLocator::getInstance()->getLevelService()->createLevel(LinkedListType::DOUBLE_LINKED_LIST);
        }

        void LinkedListSelectionUIController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void LinkedListSelectionUIController::update()
        {
            background_image->update();
            single_linked_list_button->update();
            double_linked_list_button->update();
            menu_button->update();
        }

        void LinkedListSelectionUIController::render()
        {
            background_image->render();
            single_linked_list_button->render();
            double_linked_list_button->render();
            menu_button->render();
        }

        void LinkedListSelectionUIController::show()
        {
            background_image->show();
            single_linked_list_button->show();
            double_linked_list_button->show();
            menu_button->show();
        }

        void LinkedListSelectionUIController::destroy()
        {
            delete (background_image);
            delete (single_linked_list_button);
            delete (double_linked_list_button);
            delete (menu_button);
        }
    }
}