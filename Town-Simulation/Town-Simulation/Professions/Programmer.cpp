#include <stdio.h>
#include "Programmer.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Programmer::Programmer(const std::string& type) : Profession(type) {}

int Programmer::get_salary() const{
    return Constants::PROGRAMMER_MIN_SALARY + (std::rand() % (Constants::PROGRAMMER_MAX_SALARY - Constants::PROGRAMMER_MIN_SALARY + 1));
}

void Programmer::monthly_update(Resident& resident){
    resident_info info = resident.get_resident_info();
    info.set_happiness(std::max(info.get_happiness() - 1, 0));
}

Profession* Programmer::clone() const{
    return new Programmer(*this);
}
