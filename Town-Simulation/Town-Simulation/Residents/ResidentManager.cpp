#include <stdio.h>
#include "ResidentManager.h"
#include "Building.h"
#include "City.h"

void ResidentManager::addResident(City* city, int x, int y, Resident* resident)
{
    if (x < 0 || y < 0 || x >= city->get_width() || y >= city->get_height())
        return;
    
    Building* building = city->get_building_at(x, y);
    if (building) {
        building->add_resident(resident);
        resident->set_building(building);
    }
}

void ResidentManager::removeResident(City* city, int x, int y, const std::string& name) {
    if (x < 0 || y < 0 || x >= city->get_width() || y >= city->get_height()) {
        return;
    }
    Building* building = city->get_building_at(x, y);
    if (building) {
        building->remove_resident(name);
        
    }
}
