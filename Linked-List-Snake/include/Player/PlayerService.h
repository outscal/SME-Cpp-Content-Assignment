#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Level/LevelService.h"
#include "Player/SnakeController.h"

namespace Player
{
	using namespace Level;
	class SnakeController;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer(LinkedListType level_type);

		int getSnakeSize();
		int getPlayerScore();
		bool isSnakeSizeMinimum();
		TimeComplexity getTimeComplexity();
		bool isPlayerDead();
		LinkedListOperations getLastOperation();
		SnakeState getSnakeState();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}