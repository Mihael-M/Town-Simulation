#include <stdio.h>
#include "Building.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

Building::Building(const BuildingType type, Location* loc, size_t capacity) : type(type){
    this->loc = loc->clone();
    residents.reserve(capacity);
    generate_random_residents();
}

void Building::add_resident(Resident *resident){
    if (is_full())
        throw std::overflow_error("The building can not hold any more residents!");
    
    residents.push_back(resident);
}

void Building::remove_resident(const std::string &name) {
    for (size_t i = 0; i < residents.size(); ++i) {
        if (residents[i] && residents[i]->get_name() == name) {
            delete residents[i];
            residents.erase(residents.begin() + i);
            return;
        }
    }
}

std::vector<Resident*> Building::get_residents() const{
    return residents;
}


void Building::free_dynamic(){
    for(int i = 0;i < residents.size(); i++)
            delete residents[i];
    
}

Building::~Building(){
    free_dynamic();
    residents.clear();
}

size_t Building::get_size() const{
    return residents.size();
}

size_t Building::get_capacity() const{
    return residents.capacity();
}

bool Building::is_empty() const{
    return residents.size() == 0;
}

bool Building::is_full() const{
    return residents.size() == residents.capacity();
}

size_t Building::generate_number_residents()
{
    return Constants::DEFAULT_INITIAL_RESIDENTS + (std::rand() % (Constants::MAX_INITIAL_RESIDENTS - Constants::DEFAULT_INITIAL_RESIDENTS + 1));
}

void Building::generate_random_residents()
{
    int numberOfResidents = std::rand() % get_capacity() - 1;
    for(int i = 0; i < numberOfResidents; i++)
    {
        residents.push_back(new Resident(this));
    }
}

