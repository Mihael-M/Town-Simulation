#include <stdio.h>
#include "Teacher.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

int Teacher::get_salary() const
{
    return TeacherSalary::MIN_SALARY + (std::rand() + (TeacherSalary::MAX_SALARY - TeacherSalary::MIN_SALARY + 1));
}

void Teacher::monthly_update(Resident* resident)
{
    int happiness = resident->get_happiness();
    resident->set_happiness(std::min(100, happiness + 1));    
}

std::string Teacher::get_name() const
{
    return "Teacher";
}
