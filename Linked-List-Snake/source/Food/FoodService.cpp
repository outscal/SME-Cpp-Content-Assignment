#include "Food/FoodService.h"
#include "Global/ServiceLocator.h"
#include "Food/FoodItem.h"
#include "Level/LevelModel.h"
#include "Player/PlayerService.h"
#include <iostream>

namespace Food
{
	using namespace Time;
	using namespace Global;
	using namespace Level;
	using namespace Player;

	FoodService::FoodService() : random_engine(random_device())
	{
		current_food_item = nullptr;
	}

	FoodService::~FoodService()
	{
		destroyFood();
	}

	void FoodService::initialize()
	{
		elapsed_duration = spawn_duration;
	}

	void FoodService::update()
	{
		if (current_spawning_status == FoodSpawningStatus::ACTIVE)
		{
			updateElapsedDuration();
			handleFoodSpawning();
		}

		if (current_food_item) current_food_item->update();
	}

	void FoodService::render()
	{
		if (current_food_item) current_food_item->render();
	}

	void FoodService::startFoodSpawning()
	{
		current_spawning_status = FoodSpawningStatus::ACTIVE;

		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();
	}

	void FoodService::stopFoodSpawning()
	{
		current_spawning_status = FoodSpawningStatus::IN_ACTIVE;
		destroyFood();
		reset();
	}

	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* food = new FoodItem();
		food->initialize(position, cell_width, cell_height, type);
		return food;
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(getValidSpawnPosition(), getRandomFoodType());
	}

	sf::Vector2i FoodService::getValidSpawnPosition()
	{
		std::vector<sf::Vector2i> player_position_data = ServiceLocator::getInstance()->getPlayerService()->getCurrentSnakePositionList();
		std::vector<sf::Vector2i> elements_position_data = ServiceLocator::getInstance()->getElementService()->getElementsPositionList();
		sf::Vector2i spawn_position;

		do spawn_position = getRandomPosition();
		while (!isValidPosition(player_position_data, elements_position_data, spawn_position));

		return spawn_position;
	}

	sf::Vector2i FoodService::getRandomPosition()
	{
		// Co-ordinate distribution i.e. selecting random position for food.
		std::uniform_int_distribution<int> x_distribution(0, LevelModel::number_of_columns - 1);
		std::uniform_int_distribution<int> y_distribution(0, LevelModel::number_of_rows - 1);

		int x_position = static_cast<int>(x_distribution(random_engine));
		int y_position = static_cast<int>(y_distribution(random_engine));

		return sf::Vector2i(x_position, y_position);
	}

	FoodType FoodService::getRandomFoodType()
	{
		if (ServiceLocator::getInstance()->getPlayerService()->isSnakeSizeMinimum())
		{
			int randomValue = std::rand() % (FoodItem::number_of_foods - FoodItem::number_of_healthy_foods);
			return static_cast<FoodType>(randomValue);
		}
		else
		{
			int randomValue = std::rand() % (FoodItem::number_of_foods);
			return static_cast<FoodType>(randomValue);
		}
	}

	bool FoodService::isValidPosition(std::vector<sf::Vector2i> player_position_data, std::vector<sf::Vector2i> elements_position_data, sf::Vector2i food_position)
	{
		for (int i = 0; i < player_position_data.size(); i++)
		{
			if (food_position == player_position_data[i]) return false;
		}

		for (int i = 0; i < elements_position_data.size(); i++)
		{
			if (food_position == elements_position_data[i]) return false;
		}

		return true;
	}

	void FoodService::destroyFood()
	{
		if (current_food_item) delete(current_food_item);
		current_food_item = nullptr;
	}

	void FoodService::updateElapsedDuration()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void FoodService::handleFoodSpawning()
	{
		if (ServiceLocator::getInstance()->getPlayerService()->isPlayerDead()) return;

		if (elapsed_duration >= spawn_duration)
		{
			destroyFood();
			reset();
			spawnFood();
		}
	}

	void FoodService::reset()
	{
		elapsed_duration = 0.f;
	}

	bool FoodService::processFoodCollision(LinkedListLib::Node* head_node, FoodType& out_food_type)
	{
		if (current_food_item && current_food_item->getFoodPosition() == head_node->body_part.getPosition())
		{
			out_food_type = current_food_item->getFoodType();
			return true;
		}

		return false;
	}
}