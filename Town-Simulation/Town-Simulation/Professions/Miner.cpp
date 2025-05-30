#include <stdio.h>
#include "Miner.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Miner::Miner(std::string& type) : Profession(type) {}

int Miner::get_salary() const
{
    return MinerSalary::MIN_SALARY + (std::rand() + (MinerSalary::MAX_SALARY - MinerSalary::MIN_SALARY - 1));
}

void Miner::monthly_update(Resident* resident)
{
    int life = resident->get_life_points();
    resident->set_life_points(std::max(0, life - 1));
}

const std::string& Miner::get_name() const
{
    return name;
}
