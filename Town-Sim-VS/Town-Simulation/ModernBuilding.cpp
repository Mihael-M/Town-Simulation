#include <stdio.h>
#include "ModernBuilding.h"
#include "BuildingType.h"

ModernBuilding::ModernBuilding(Location* loc) : Building(BuildingType::Modern, loc)  {}

double ModernBuilding::calculate_rent() const {
    double base_rent = get_base_rent();
    return base_rent *= loc->rent_multiplier();
}

double ModernBuilding::get_base_rent() const {
    return BASE_RENT;
}

Building* ModernBuilding::clone() const {
    return new ModernBuilding(*this);
}
