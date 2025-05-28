#include <stdio.h>
#include "City.h"
#include <stdexcept>
#include <iostream>
#include <cmath>


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

void City:: add_building(int x, int y, const Building *building)
{
    if(x < 0 || y < 0 || x >= width || y >= height)
    {
        throw std::invalid_argument("Wrong building information, can't be added!");
    }
//    building->set_location(is_central(x, y), is_peripheral(x, y));
//    grid[x][y] = building;
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

City::~City(){
    freeDynamic();
}
