#include <stdio.h>
#include "DormitoryBuilding.h"
#include "BuildingType.h"

DormitoryBuilding::DormitoryBuilding(Location* loc) : Building(BuildingType::Dormitory, loc)  {}

double DormitoryBuilding::calculate_rent() const {
    
    double base_rent = get_base_rent();
    return base_rent *= loc->rent_multiplier();
}

double DormitoryBuilding::get_base_rent() const {
    return BASE_RENT;
}

Building* DormitoryBuilding::clone() const {
    return new DormitoryBuilding(*this);
}
