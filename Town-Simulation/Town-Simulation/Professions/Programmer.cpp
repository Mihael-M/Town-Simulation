#include <stdio.h>
#include "Programmer.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

int Programmer::get_salary() const
{
    return ProgrammerSalary::MIN_SALARY + (std::rand() + (ProgrammerSalary::MAX_SALARY - ProgrammerSalary::MIN_SALARY + 1));
}

void Programmer::monthly_update(Resident* resident)
{
    int happiness = resident->get_happiness();
    resident->set_happiness(std::max(happiness - 1, 0));
}

std::string Programmer::get_name() const
{
    return "Programmer";
}
