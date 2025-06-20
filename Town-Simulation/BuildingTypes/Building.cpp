#include <stdio.h>
#include "Building.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "LocationType.h"

Building::Building(const BuildingType type, Location* loc, size_t capacity) : type(type){
    this->loc = loc->clone();
    residents.reserve(capacity);
}


void Building::add_resident(Resident *resident){
    if (is_full())
        throw std::overflow_error("The building can not hold any more residents!");
    
    residents.push_back(resident);
}

void Building::remove_resident(const std::string &name) {
    for (size_t i = 0; i < residents.size(); ++i) {
           if (residents[i] && residents[i]->get_name() == name) {
               residents.erase(residents.begin() + i);
               return;
           }
       }
    throw std::runtime_error("No resident with that name found in this building!");
}

std::vector<Resident*> Building::get_residents() const{
    return residents;
}


void Building::free_dynamic(){
    delete loc;
}

Building::~Building(){
    free_dynamic();
    residents.clear();
}

Building::Building(const Building& other) : type(other.type)
{
    residents.reserve(other.residents.capacity());
    copy_dynamic(other);
}

Building& Building::operator=(const Building& other)
{
    if(this != &other)
    {
        type = other.type;
        free_dynamic();
        residents.clear();
        residents.reserve(other.residents.capacity());
        copy_dynamic(other);
    }
    return *this;
}

void Building::copy_dynamic(const Building& other)
{
    for(int i = 0; i < other.residents.size(); i++)
        residents.push_back(new Resident(*other.residents[i]));
    loc = other.loc->clone();
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

void Building::print_residents(std::ostream& os) const
{
    for(int i = 0; i < residents.size(); i++)
    {
        os<< "           ";
        os<< residents[i]->get_name() << std::endl;
        residents[i]->print_info(os);
    }
}

void Building::print_building(std::ostream& os) const
{
    os << "        ";
    switch (type)
    {
        case BuildingType::Modern:
            os << "Modern" << std::endl;
            break;
        case BuildingType::PanelBlock:
            os << "PanelBlock" << std::endl;
            break;
        case BuildingType::Dormitory:
            os << "Dormitory" << std::endl;
            break;
        default:
            os << "Unknown type" << std::endl;
            break;
    }
    os << "        ";
    switch (loc->get_type())
    {
        case LocationType::Central:
            os << "Central location" << std::endl;
            break;
        case LocationType::Peripheral:
            os << "Peripheral location" << std::endl;
            break;
        default:
            os << "Unknown location" << std::endl;
            break;
    }
}

void Building::save_building_to_file(std::ofstream& ofs) const
{
    switch (type)
    {
        case BuildingType::Modern:
            ofs << "Modern" << std::endl;
            break;
        case BuildingType::PanelBlock:
            ofs << "PanelBlock" << std::endl;
            break;
        case BuildingType::Dormitory:
            ofs << "Dormitory" << std::endl;
            break;
        default:
            ofs << "Unknown type" << std::endl;
            break;
    }
    ofs<< residents.capacity() <<std::endl;
}

void Building::load_residents_from_file(std::ifstream& ifs, int capacity)
{
    residents.clear();
    residents.reserve(capacity);
}
