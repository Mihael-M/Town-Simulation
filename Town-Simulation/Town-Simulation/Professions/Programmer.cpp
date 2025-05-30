#include <stdio.h>
#include "Programmer.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Programmer::Programmer(std::string& type) : Profession(type) {}

int Programmer::get_salary() const
{
    return ProgrammerSalary::MIN_SALARY + (std::rand() + (ProgrammerSalary::MAX_SALARY - ProgrammerSalary::MIN_SALARY + 1));
}

void Programmer::monthly_update(Resident* resident)
{
    int happiness = resident->get_happiness();
    resident->set_happiness(std::max(happiness - 1, 0));
}

const std::string& Programmer::get_name() const
{
    return name;
}
