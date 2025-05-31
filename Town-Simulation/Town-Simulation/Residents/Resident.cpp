#include <stdio.h>
#include "Resident.h"
#include "Constants.hpp"
#include <iostream>
#include <stdexcept>


void Resident::freeDynamic(){
    delete profession;
}

Resident::~Resident(){
    freeDynamic();
    profession = nullptr;
    building = nullptr;
}

void Resident::set_building(Building* building)
{
    this->building = building;
}


Resident::Resident(const std::string& name, Profession* job, const resident_info& info, Building* building) : info(info) , name(name), profession(job), building(building) {}

void Resident::pay_rent(){    
    int curr_balance = info.get_money();
    int rent = building->calculate_rent();
    
    curr_balance -= rent;
    
    if (curr_balance < 0)
        curr_balance = 0;
}


const std::string& Resident::get_name() const {
    return name;
}

void Resident::pay_for_food(){
    int curr_balance = info.get_money();
    
    curr_balance -= Constants::FOOD_EXPENSES;
    if(curr_balance < 0)
        curr_balance = 0;
}


void Resident::receive_salary() {
    info.set_money(info.get_money() + profession->get_salary());
    profession->monthly_update(this);
}

resident_info Resident::get_resident_info() const{
    return info;
}

void Resident::record_snapshot(int currentDay)
{
    history.push_back({currentDay, info});
}



void Resident::live_day(bool isFirstDayOfMonth, int currentDay) {
    if (isFirstDayOfMonth)
        pay_rent();
    
    pay_for_food();
    record_snapshot(currentDay);
}

void Resident::print_info() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Profession: " << profession->get_type() << "\n";
    std::cout << "Happiness: " << info.get_happiness() << ", Money: " << info.get_money() << ", Life: " << info.get_life_points() << std::endl;
}
