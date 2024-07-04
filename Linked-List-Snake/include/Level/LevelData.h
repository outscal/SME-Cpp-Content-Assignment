#pragma once
#include "Level/LevelService.h"
#include "Element/ElementData.h"

namespace Level
{
    struct LevelData
    {
        LevelData(LevelNumber ind, std::vector<Element::ElementData>* data_list)
        {
            level_index = ind;
            element_data_list = data_list;
        }

        LevelNumber level_index;
        std::vector<Element::ElementData>* element_data_list;
    };
}