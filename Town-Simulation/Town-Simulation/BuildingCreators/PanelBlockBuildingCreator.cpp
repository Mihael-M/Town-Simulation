#include <stdio.h>
#include "PanelBlockBuildingCreator.h"
#include "PanelBlockBuilding.h"

PanelBlockBuildingCreator::PanelBlockBuildingCreator() : BuildingCreator(BuildingType::PanelBlock) {}

Building* PanelBlockBuildingCreator::create_building(Location* loc) const
{
    return new PanelBlockBuilding(loc);
}
