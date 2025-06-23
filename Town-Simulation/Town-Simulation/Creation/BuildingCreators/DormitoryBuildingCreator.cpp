#include <stdio.h>
#include "DormitoryBuildingCreator.h"
#include "DormitoryBuilding.h"

DormitoryBuildingCreator::DormitoryBuildingCreator() : BuildingCreator(BuildingType::Dormitory) {}

Building* DormitoryBuildingCreator::create_building(Location* loc) const
{
    return new DormitoryBuilding(loc);
}
