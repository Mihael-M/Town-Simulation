#include <stdio.h>
#include "PanelBlockBuilding.h"
#include "BuildingType.h"

PanelBlockBuilding::PanelBlockBuilding(int capacity) : Building(BuildingType::PanelBlock, capacity)  {}

double PanelBlockBuilding::calculate_rent() const {
    double rent = get_base_rent();
    if (isCentral) rent *= 2.5;
    else if (isPeripheral) rent *= 0.8;
    return rent;
}

double PanelBlockBuilding::get_base_rent() const {
    return 500.0;
}

Building* PanelBlockBuilding::clone() const {
    return new PanelBlockBuilding(*this);
}
