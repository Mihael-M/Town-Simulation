#include <stdio.h>
#include "PanelBlockBuilding.h"
#include "BuildingType.h"

PanelBlockBuilding::PanelBlockBuilding(Location* loc,size_t capacity) : Building(BuildingType::PanelBlock,loc, capacity)  {}

double PanelBlockBuilding::calculate_rent() const {
    auto base_rent = get_base_rent();
    return base_rent *= loc->rent_multiplier();
}

double PanelBlockBuilding::get_base_rent() const {
    return BASE_RENT;
}

Building* PanelBlockBuilding::clone() const {
    return new PanelBlockBuilding(*this);
}
