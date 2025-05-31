#include <stdio.h>
#include "Unemployed.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Unemployed::Unemployed(const std::string& type) : Profession(type) {}

int Unemployed::get_salary() const{
    return Constants::UNEMPLOYED_SALARY;
}

void Unemployed::monthly_update(Resident* resident){
    auto resident_info = resident->get_resident_info();
    resident_info.set_life_points(std::max(0, resident_info.get_life_points() - 1));
}

Profession* Unemployed::clone() const{
    return new Unemployed(*this);
}
