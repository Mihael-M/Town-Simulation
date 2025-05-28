#include <stdio.h>
#include "Resident.h"
#include <iostream>
void Resident::freeDynamic(){
    delete profession;
}

Resident::~Resident(){
    freeDynamic();
}



Resident::Resident(const std::string& name, Profession* job, int happiness, int money, int lifePoints)
    : name(name), profession(job), happiness(happiness), money(money), lifePoints(lifePoints) {}


void Resident::pay_rent(double amount)
{
    if(amount < 0)
        throw std::invalid_argument("The rent can not be negative.");
    
    money -= 50;
    if (money < 0) money = 0;
}
const std::string& Resident::get_name() const {
    return name;
}

int Resident::get_happiness() const {
    return happiness;
}

int Resident::get_money() const {
    return money;
}

int Resident::get_life_points() const {
    return lifePoints;
}

void Resident::receive_salary() {
    money += profession->get_salary();
    profession->monthly_update(this);
}

void Resident::record_snapshot(int currentDay) {
    ResidentSnapshot snap = { currentDay, happiness, money, lifePoints };
    history.push_back(snap);
}

void Resident::live_day(bool isFirstDayOfMonth, double rent, int currentDay) {
    if (isFirstDayOfMonth) {
        money -= rent;
    }
    pay_rent(rent);

    record_snapshot(currentDay);
}

void Resident::print_info() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Profession: " << profession->get_name() << "\n";
    std::cout << "Happiness: " << happiness << ", Money: " << money << ", Life: " << lifePoints << "\n";
}
