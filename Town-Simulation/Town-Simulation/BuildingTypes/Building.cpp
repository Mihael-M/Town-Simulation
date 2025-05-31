#include <stdio.h>
#include "Building.h"
#include <stdexcept>
#include <iostream>

Building::Building(const BuildingType type, Location* loc, size_t capacity) : type(type), capacity(capacity), residents(capacity), size(0){
    this->loc = loc->clone();
}

void Building::add_resident(Resident *resident){
    if (is_full())
        throw std::overflow_error("The building can not hold any more residents!");
    
    residents[size++] = resident;
}

void Building::remove_resident(const std::string &name){
    for(int i = 0; i < size; i++)
    {
        if(name == residents[i]->get_name())
        {
            delete residents[i];
            residents[i] = nullptr;
            return;
        }
    }
}

std::vector<Resident*> Building::get_residents() const{
    return residents;
}


void Building::freeDynamic(){
    for(int i = 0;i < size; i++)
        delete residents[i];
}

Building::~Building(){
    freeDynamic();
}

size_t Building::get_size() const{
    return size;
}

size_t Building::get_capacity() const{
    return capacity;
}

bool Building::is_empty() const{
    return size == 0;
}

bool Building::is_full() const{
    return size == capacity;
}
