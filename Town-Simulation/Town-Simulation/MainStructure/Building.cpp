#include <stdio.h>
#include "Building.h"

Building::Building(const BuildingType type, int capacity): type(type), capacity(capacity),isCentral(false),isPeripheral(false){}

void Building::add_resident(Resident *resident)
{
    residents.push_back(resident);
}

void Building::remove_resident(const std::string &name)
{
    for(int i = 0; i < residents.size(); i++)
    {
        if(name == residents[i]->get_name())
        {
            delete residents[i];
            residents.erase(residents.begin() + i);
            return;
        }
    }
}

void Building::setLocation(bool central, bool peripheral)
{
    this->isCentral = central;
    this->isPeripheral = peripheral;
}

void Building::freeDynamic()
{
    for(int i = 0;i < residents.size(); i++)
        delete residents[i];
    residents.clear();
}

Building::~Building()
{
    freeDynamic();
}
