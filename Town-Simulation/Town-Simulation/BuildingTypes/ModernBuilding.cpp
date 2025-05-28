#include <stdio.h>
#include "ModernBuilding.h"

ModernBuilding::ModernBuilding(int capacity) : Building("Modern", capacity)  {}

double ModernBuilding::calculate_rent() const {
    double rent = 1000.0;
    if (isCentral) rent *= 2.5;
    else if (isPeripheral) rent *= 0.8;
    return rent;
}

double ModernBuilding::get_base_rent() const {
    return 1000.0;
}

Building* ModernBuilding::clone() const {
    return new ModernBuilding(*this);
}
