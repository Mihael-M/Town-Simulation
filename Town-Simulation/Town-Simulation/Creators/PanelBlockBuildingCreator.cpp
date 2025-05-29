#include <stdio.h>
#include "PanelBlockBuildingCreator.h"
#include "PanelBlockBuilding.h"

PanelBlockBuildingCreator::PanelBlockBuildingCreator() : BuildingCreator(BuildingType::PanelBlock) {}

Building* PanelBlockBuildingCreator::create_building(int capacity) const
{
    return new PanelBlockBuilding(capacity);
}
