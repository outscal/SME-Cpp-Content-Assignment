#include "Level/LevelController.h"
#include "Level/LevelModel.h"
#include "Level/LevelView.h"

namespace Level
{
	using namespace Element;

	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView();
	}

	LevelController::~LevelController()
	{
		delete level_model;
		delete level_view;
	}

	void LevelController::initialize()
	{
		level_view->initialize();
		level_model->initialize(level_view->getGridWidth(), level_view->getGridHeight());
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	float LevelController::getCellWidth()
	{
		return level_model->getCellWidth();
	}

	float LevelController::getCellHeight()
	{
		return level_model->getCellHeight();
	}

	const std::vector<ElementData>& LevelController::getElementDataList(int level_to_load)
	{
		return level_model->getElementDataList(level_to_load);
	}
}