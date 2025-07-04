#include <stdio.h>
#include "Unemployed.h"
#include "Resident.h"
#include <cmath>

Unemployed::Unemployed(const std::string& type) : Profession(type) {}

int Unemployed::get_salary() const{
    return Constants::UNEMPLOYED_SALARY;
}

void Unemployed::monthly_update(Resident& resident){
    resident_info* info = resident.get_resident_info();
    info->set_life_points(std::max(0, info->get_life_points() - 1));
}

Profession* Unemployed::clone() const{
    return new Unemployed(*this);
}
