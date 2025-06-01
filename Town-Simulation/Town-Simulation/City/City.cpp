#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "City.h"
#include "BuildingRegistrations.h"


#include "BuildingFactory.h"
#include "ProfessionFactory.h"
#include "LocationFactory.h"

City::City(int width, int height) : width(width),height(height)
{
    grid.resize(height,std::vector<Building*>(width,nullptr));
    generate_random_buildings();
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
            
            add_building(x, y, newBuilding);
        }
    }
}



void City::add_building(int x, int y,Building *building)
{
    if(x < 0 || y < 0 || x >= width || y >= height)
    {
        throw std::invalid_argument("Wrong building information, can't be added!");
    }
    if(grid[x][y] != nullptr)
        return;
    
    grid[x][y] = building;
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

Building* City::get_building_at(int x, int y)
{
    if(x < 0 || y < 0 || x > width || y > height || grid[x][y] == nullptr)
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
