#include <stdio.h>
#include "Resident.h"
#include <iostream>
#include <stdexcept>


void Resident::freeDynamic(){
    delete profession;
    delete building;
}

Resident::~Resident(){
    freeDynamic();
}



Resident::Resident(const std::string& name, Profession* job, const resident_info& info, Building* building) : info(info){
    this->name = name;
    this->profession = job;
    this->building = building->clone();
    
}

void Resident::pay_rent(){    
    auto& curr_balance = info.money;
    auto rent = building->calculate_rent();
    if (curr_balance - rent < 0)
        throw "insufficient balance";
    
    curr_balance -= building->calculate_rent();
}


const std::string& Resident::get_name() const {
    return name;
}

void Resident::pay_for_food(){
    auto& curr_balance = info.money;
    if(curr_balance - Constants::FOOD_EXPENSES < 0)
        throw "insufficinet balance";
    
    curr_balance -= Constants::FOOD_EXPENSES;
}


void Resident::receive_salary() {
    info.money += profession->get_salary();
    profession->monthly_update(this);
}

resident_info Resident::get_resident_info() const{
    return info;
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
    std::cout << "Happiness: " << info.happiness << ", Money: " << info.money << ", Life: " << info.life_points << std::endl;
}
