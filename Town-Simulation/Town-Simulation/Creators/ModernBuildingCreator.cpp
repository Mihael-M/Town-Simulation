#include <stdio.h>
#include "ModernBuildingCreator.h"
#include "ModernBuilding.h"

ModernBuildingCreator::ModernBuildingCreator() : BuildingCreator(BuildingType::Modern) {}

Building* ModernBuildingCreator::create_building(int capacity) const
{
    return new ModernBuilding(capacity);
}
