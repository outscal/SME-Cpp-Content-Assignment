#pragma once
#include <vector>
#include "LevelModel.h"

namespace Level
{
    class LevelView;

    class LevelController
    {
    private:
        LevelModel* level_model;
        LevelView* level_view;

    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();

        float getCellWidth();
        float getCellHeight();

        const std::vector<Element::ElementData>& getElementDataList(int level_to_load);
    };
}