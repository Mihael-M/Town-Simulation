#include <stdio.h>
#include "Building.h"
#include <iostream>

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

std::vector<Resident*> Building::get_residents() const
{
    return residents;
}










//!!!!!!!!!!!!!!!!!!!!!!
// __________________________________________ not such a good idea but for now...
void Building::print_type() const{
    switch(type){
        case BuildingType::Dormitory : std::cout<<"Dormitory"<<std::endl; break;
        case BuildingType::PanelBlock : std::cout<<"Panel block"<<std::endl; break;
        case BuildingType::Modern : std::cout<<"Modern"<<std::endl; break;
        default: std::cout << "Unknown";
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
