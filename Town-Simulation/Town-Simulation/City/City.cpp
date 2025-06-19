#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "City.h"
#include "BuildingRegistrations.h"


#include "BuildingFactory.h"
#include "LocationFactory.h"

City::City(int width, int height) : width(width),height(height)
{
    grid.resize(width, std::vector<Building*>(height, nullptr));
    generate_random_buildings();
}

City::City(int width, int height, std::vector<std::vector<Building*>>& grid) : width(width), height(height) {
    this->grid = std::move(grid);
}

City::City(const City& other) : width(other.width), height(other.height)
{
    copy_dynamic(other);
}

City::City(std::ifstream& ifs)
{
    if (!(ifs >> width >> height)) {
        throw std::runtime_error("Failed to read city dimensions");
    }
    grid.resize(width, std::vector<Building*>(height, nullptr));

    BuildingFactory* factory = BuildingFactory::get_factory();
    LocationFactory locFactory(width, height);
    std::string line;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (grid[x][y] == nullptr) {
                    std::getline(ifs, line);
                    if (line.empty()) std::getline(ifs, line);
                    
                    BuildingType type;
                    if (line == "Modern") type = BuildingType::Modern;
                    else if (line == "PanelBlock") type = BuildingType::PanelBlock;
                    else if (line == "Dormitory") type = BuildingType::Dormitory;
                    else throw std::runtime_error("Unknown building type: " + line);
                    
                    Location* loc = locFactory.create_location(x, y);
                    Building* building = factory->create_building(type, loc);
                    int capacity;
                    ifs >>capacity;
                    building->load_residents_from_file(ifs,capacity);
                    grid[x][y] = building;
                }
        }
    }
}

City& City::operator=(const City& other)
{
    if(this != &other)
    {
        width = other.width;
        height = other.height;
        free_dynamic();
        copy_dynamic(other);
    }
    return *this;
}

Location* City::generate_random_location(int x, int y) const
{
    LocationFactory factory = LocationFactory(width, height);
    
    return factory.create_location(x, y);
}


void City::generate_random_buildings()
{
    BuildingFactory* factory = BuildingFactory::get_factory();
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            BuildingType buildingType = (BuildingType)(std::rand() % Constants::BUILDING_TYPES);
            
            Building* newBuilding = factory->create_building(buildingType, generate_random_location(x, y));
            
            Coordinates coords(x, y);
            
            add_building(coords, newBuilding);
        }
    }
}



void City::add_building(const Coordinates& coordinates, Building* building)
{
    int x = coordinates.get_x();
    int y = coordinates.get_y();

    if (x < 0 || y < 0 || x >= width || y >= height)
    {
        throw std::invalid_argument("Wrong building information, can't be added!");
    }

    grid[x][y] = building;
}

void City::free_dynamic() {
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            delete grid[x][y];
        }
    }
}

Building* City::get_building_at(const Coordinates& corrdinates)
{
    int x = corrdinates.get_x();
    int y = corrdinates.get_y();

    if (x < 0 || y < 0 || x >= width || y >= height || grid[x][y] == nullptr)
        throw std::invalid_argument("Invalid position for building.");

    return grid[x][y];
}

int City::get_width() const
{
    return width;
}

int City::get_height() const
{
    return height;
}




City::~City(){
    free_dynamic();
}

void City::copy_dynamic(const City& other)
{
    grid.resize(other.width, std::vector<Building*>(other.height, nullptr));

    for (int x = 0; x < other.width; x++) {
        for (int y = 0; y < other.height; y++) {
            if (other.grid[x][y]) {
                grid[x][y] = other.grid[x][y]->clone();
            }
        }
    }
}

void City::save_city_to_file(std::ofstream& ofs) const
{
    ofs<<width<<" "<<height<<std::endl;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            grid[x][y]->save_building_to_file(ofs);
        }
    }

    
}
