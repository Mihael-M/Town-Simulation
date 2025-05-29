#include <stdio.h>
#include "DormitoryBuilding.h"
#include "BuildingType.h"

DormitoryBuilding::DormitoryBuilding(int capacity) : Building(BuildingType::Dormitory, capacity)  {}

double DormitoryBuilding::calculate_rent() const {
    
    double rent = get_base_rent();
    if (isCentral) rent *= 2.5;
    else if (isPeripheral) rent *= 0.8;
    return rent;
}

double DormitoryBuilding::get_base_rent() const {
    return 40.0;
}

Building* DormitoryBuilding::clone() const {
    return new DormitoryBuilding(*this);
}
