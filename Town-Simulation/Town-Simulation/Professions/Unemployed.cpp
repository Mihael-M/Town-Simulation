#include <stdio.h>
#include "Unemployed.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Unemployed::Unemployed(std::string& type) : Profession(type) {}

int Unemployed::get_salary() const
{
    return 0;
}

void Unemployed::monthly_update(Resident* resident)
{
    int life = resident->get_life_points();
    resident->set_life_points(std::max(0, life - 1));
}

const std::string& Unemployed::get_name() const
{
    return name;
}
