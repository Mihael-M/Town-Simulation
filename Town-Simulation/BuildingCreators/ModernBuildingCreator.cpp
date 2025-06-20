#include <stdio.h>
#include "ModernBuildingCreator.h"
#include "ModernBuilding.h"

ModernBuildingCreator::ModernBuildingCreator() : BuildingCreator(BuildingType::Modern) {}

Building* ModernBuildingCreator::create_building(Location* loc) const
{
    return new ModernBuilding(loc);
}
