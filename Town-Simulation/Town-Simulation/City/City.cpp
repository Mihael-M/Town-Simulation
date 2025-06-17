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
    grid.resize(height,std::vector<Building*>(width,nullptr));
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
    grid.resize(height, std::vector<Building*>(width, nullptr));

    BuildingFactory* factory = BuildingFactory::get_factory();
    LocationFactory locFactory(width, height);
    std::string line;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (grid[y][x] == nullptr) {
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
                    grid[y][x] = building;
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
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            BuildingType buildingType = (BuildingType)(std::rand() % Constants::BUILDING_TYPES);
            
            Building* newBuilding = factory->create_building(buildingType, generate_random_location(x, y));
            
            Coordinates coords(x, y);
            
            add_building(coords, newBuilding);
        }
    }
}



void City::add_building(const Coordinates& coordinates,Building *building)
{
    if(coordinates.get_x() < 0 || coordinates.get_y() < 0 || coordinates.get_x() >= width || coordinates.get_y() >= height)
    {
        throw std::invalid_argument("Wrong building information, can't be added!");
    }
    
    grid[coordinates.get_x()][coordinates.get_y()] = building;
}

void City::free_dynamic() {
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            delete grid[i][j];
        }
    }
}

Building* City::get_building_at(const Coordinates& corrdinates)
{
    if(corrdinates.get_x() < 0 || corrdinates.get_y() < 0 || corrdinates.get_x() > width || corrdinates.get_y() > height || grid[corrdinates.get_x()][corrdinates.get_y()] == nullptr)
        throw std::invalid_argument("Invalid position for building.");
    
    return grid[corrdinates.get_x()][corrdinates.get_y()];
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
    grid.resize(other.height, std::vector<Building*>(other.width, nullptr));

    for (int y = 0; y < other.height; y++) {
        for (int x = 0; x < other.width; x++) {
            if (other.grid[y][x]) {
                grid[y][x] = other.grid[y][x]->clone();
            }
        }
    }
}

void City::save_city_to_file(std::ofstream& ofs) const
{
    ofs<<width<<" "<<height<<std::endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x]->save_building_to_file(ofs);
        }
    }

    
}
