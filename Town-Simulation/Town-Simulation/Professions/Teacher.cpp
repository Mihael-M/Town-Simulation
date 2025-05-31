#include <stdio.h>
#include "Teacher.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Teacher::Teacher(const std::string& type) : Profession(type) {}

int Teacher::get_salary() const{
    return Constants::TEACHER_MIN_SALARY + (std::rand() + (Constants::TEACHER_MAX_SALARY - Constants::TEACHER_MIN_SALARY + 1));
}

void Teacher::monthly_update(Resident* resident){
    auto resident_info = resident->get_resident_info();
    
    resident_info.set_happiness(std::min(100, resident_info.happiness));
}

Profession* Teacher::clone() const{
    return new Teacher(*this);
}
