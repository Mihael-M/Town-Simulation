#include <stdio.h>
#include "Miner.h"
#include "Resident.h"
#include <cstdlib>
#include <cmath>

Miner::Miner(const std::string& type) : Profession(type) {}

int Miner::get_salary() const{
    return Constants::MINER_MIN_SALARY + (std::rand() + (Constants::MINER_MAX_SALARY - Constants::MINER_MIN_SALARY - 1));
}

void Miner::monthly_update(Resident* resident){
    int life = resident->get_resident_info().get_life_points();
    resident->get_resident_info().set_life_points(std::max(0, life - 1));
}

Profession* Miner::clone() const{
    return new Miner(*this);
}
