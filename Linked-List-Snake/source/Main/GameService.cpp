#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "UI/UIService.h"

namespace Main
{
	using namespace Global;
	using namespace Graphics;
	using namespace Event;
	using namespace UI;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService() { service_locator = nullptr; }

	GameService::~GameService() { destroy(); }

	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showSplashScreen();
	}

	void GameService::initializeVariables() { game_window = service_locator->getGraphicService()->getGameWindow(); }

	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::getInstance()->getUIService()->showScreen();
	}

	bool GameService::isRunning() { return service_locator->getGraphicService()->isGameWindowOpen(); }

	// Main Game Loop.
	void GameService::update()
	{
		// Process Events.
		service_locator->getEventService()->processEvents();

		// Update Game Logic.
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear();
		service_locator->render();
		game_window->display();
	}

	void GameService::destroy() { service_locator->deleteServiceLocator(); }

	void GameService::setGameState(GameState new_state) { current_state = new_state; }

	GameState GameService::getGameState() { return current_state; }
}