#include <stdio.h>
#include "ResidentManager.h"
#include "Building.h"
#include "City.h"
#include <iostream>
#include <stdexcept>

void ResidentManager::add_resident(Building* building, Resident* resident)
{
    building->add_resident(resident);
    residents.push_back(ResidentEditor(resident));
}

void ResidentManager::remove_resident(Building* building, const std::string& name, unsigned currentDay)
{
    building->remove_resident(name);
    remove(currentDay,name);
}

void ResidentManager::remove_resident(City* city, const std::string& name, unsigned currentDay, size_t index)
{
    Resident* resident = residents[index].get_resident();
    Building* building = city->get_building_at(resident->get_resident_info()->get_coordinates());
    building->remove_resident(name);
    resident->get_resident_info()->set_removal_day(currentDay);
    if(resident->get_resident_info()->get_cause() != RemovalCause::RemovedManually)
        resident->get_resident_info()->set_cause(RemovalCause::Died);
}

void ResidentManager::remove(unsigned currentDay, const std::string& name)
{
    for(int i = 0; i < residents.size(); i++)
    {
        if(name == residents[i].get_resident()->get_name()){
            Resident* resident = residents[i].get_resident();
            resident->get_resident_info()->set_removal_day(currentDay);
            resident->get_resident_info()->set_born(currentDay);
            resident->get_resident_info()->set_cause(RemovalCause::RemovedManually);
        }
    }
}

void ResidentManager::generate_random_residents(City* city, unsigned currentDay)
{
    if(!residents.empty())
        residents.clear();
    for(int y = 0; y < city->get_height(); y++)
    {
        for(int x = 0; x < city->get_width(); x++)
        {
            Coordinates coords(x, y);
            Building* building = city->get_building_at(coords);
            int numberOfResidents = 1 + (std::rand() % building->get_capacity());
            for(int i = 0; i < numberOfResidents; i++)
            {
                
                resident_info* info = new resident_info(coords,currentDay);
                add_resident(building, new Resident(info));
            }
        }
    }
}

std::vector<ResidentEditor>& ResidentManager::get_residents()
{
    return residents;
}

void ResidentManager::bring_back(City* city, size_t index)
{
    
    Resident* resident = residents[index].get_resident();
    Building* building = city->get_building_at(resident->get_resident_info()->get_coordinates());
    resident->get_resident_info()->set_removal_day(-1);
    if(resident->get_resident_info()->get_cause() != RemovalCause::RemovedManually)
        resident->get_resident_info()->set_cause(RemovalCause::None);
    building->add_resident(resident);
}

void ResidentManager::remove_resident(size_t index,City* city, const std::string& name)
{
    city->get_building_at(residents[index].get_resident()->get_resident_info()->get_coordinates())->remove_resident(name);
    residents[index].get_resident()->get_resident_info()->set_removal_day(residents[index].get_resident()->get_resident_info()->get_born());
}

void ResidentManager::save_residents_to_file(std::ofstream& ofs) const
{
    size_t size = residents.size();
    ofs<<size<<std::endl;
    for(int i = 0; i < size; i++){
        residents[i].save_memento_to_file(ofs);
    }
}

void ResidentManager::load_residents_from_file(City* city,std::ifstream& ifs)
{
    residents.clear();
    size_t size;
    ifs>>size;
    for(int i = 0; i < size; i++)
    {
        int x,y;
        ifs >> x >> y;
        Coordinates coords(x, y);
        ResidentEditor editor(ifs);
        Building* building = city->get_building_at(coords);
        residents.push_back(editor);
        building->add_resident(editor.get_resident());
    }
}

void ResidentManager::print_resident(const Coordinates& coords, const std::string& name)
{

    for(int i = 0; i < residents.size(); i++)
    {
        if(residents[i].get_resident()->get_resident_info()->get_coordinates() == coords && residents[i].get_resident()->get_name() == name && residents[i].get_resident()->get_resident_info()->is_alive()){
                std::cout<<residents[i].get_resident()->get_name() << std::endl;
                residents[i].get_resident()->print_info(std::cout);
                std::cout<<"History: "<<std::endl;
                residents[i].print_history(std::cout);
                return;
        }
    }
    throw std::runtime_error("Resident with that name does not exist!");
    
}

void ResidentManager::forward(bool isFirstDayOfMonth, int currentDay, City* city, size_t index)
{
    
    if(index < residents.size()){
        Resident* resident = residents[index].get_resident();
        ResidentEditor& residentEditor = residents[index];
        Building* building = city->get_building_at(resident->get_resident_info()->get_coordinates());
        residentEditor.go_forward(isFirstDayOfMonth, currentDay, building);
    }
}

size_t ResidentManager::size() const
{
    return residents.size();
}

