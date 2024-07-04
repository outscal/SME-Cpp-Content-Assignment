#include "Graphics/GraphicService.h"

namespace Graphics
{
	GraphicService::GraphicService()
	{
		game_window = nullptr;
	}

	GraphicService::~GraphicService()
	{
		onDestroy();
	}

	void GraphicService::initialize()
	{
		game_window = createGameWindow();
		setFrameRate(frame_rate);
	}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		configureVideoMode();
		return new sf::RenderWindow(video_mode, game_window_title, sf::Style::Fullscreen);
	}

	void GraphicService::configureVideoMode()
	{
		video_mode = *(new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel));
	}

	void GraphicService::onDestroy()
	{
		delete(game_window);
	}

	void GraphicService::setFrameRate(int frame_rate_to_set)
	{
		game_window->setFramerateLimit(frame_rate_to_set);
	}

	void GraphicService::update() { }

	void GraphicService::render() { }

	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}

	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}
}