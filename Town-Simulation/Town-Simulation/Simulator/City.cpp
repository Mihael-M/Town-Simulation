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


void City::simulate_day() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Building* building = grid[i][j];
                auto residents = building->get_residents();
                residents.erase(std::remove_if(residents.begin(), residents.end(),
                    [](const Resident* r) {
                        return r->get_money() <= 0 || r->get_happiness() <= 0 || r->get_life_points() <= 0;
                    }), residents.end());
            }
        }
    currentDay++;
}
   


void City::simulate_month() {
    for (int day = 0; day < 30; day++) {
        simulate_day();
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Building* building = grid[i][j];
            if (building != nullptr) {
                auto residents = building->get_residents();
                for (Resident* r : residents) {
                    r->receive_salary();
                }
            }
        }
    }
}

void City::print_status() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Building* building = grid[i][j];
            if (building != nullptr) {
                std::cout << "Building type: ";
                building->print_type();
                std::cout<< "\n";
                std::cout << "Residents: ";
                auto residents = building->get_residents();
                for (const Resident* r : residents) {
                    std::cout << r->get_name() << " ";
                }
                std::cout << "\n";
            }
        }
    }
}

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
