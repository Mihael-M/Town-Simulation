#include <stdio.h>
#include "City.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "BuildingRegistrations.h"

City::City(int width, int height) : width(width),height(height),currentDay(1)
{
    grid.resize(height,std::vector<Building*>(width,nullptr));
}

bool City::is_central(int x, int y) const
{
    int centerX = width / 2;
    int centerY = height / 2;
    double distance = std::sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
    return distance <= std::min(width, height) / 8.0;
}

bool City::is_peripheral(int x, int y) const
{
    return !is_central(x, y);
}

void City:: add_building(int x, int y,Building *building)
{
    if(x < 0 || y < 0 || x >= width || y >= height)
    {
        throw std::invalid_argument("Wrong building information, can't be added!");
    }
    building->setLocation(is_central(x, y), is_peripheral(x, y));
    grid[x][y] = building;
}

void City::freeDynamic() {
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            delete grid[i][j];
        }
    }
}
// ------------------------------


void simulate_day();

void simulate_month();

void print_status();

// ------------------------------

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
    freeDynamic();
}
