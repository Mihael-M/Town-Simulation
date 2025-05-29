#include <stdio.h>
#include "DormitoryBuildingCreator.h"
#include "DormitoryBuilding.h"

DormitoryBuildingCreator::DormitoryBuildingCreator() : BuildingCreator(BuildingType::Dormitory) {}

Building* DormitoryBuildingCreator::create_building(int capacity) const
{
    return new DormitoryBuilding(capacity);
}
