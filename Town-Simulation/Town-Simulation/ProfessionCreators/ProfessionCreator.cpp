#include <stdio.h>
#include "ProfessionCreator.h"

ProfessionCreator::ProfessionCreator(const std::string& type) : type(type) {}

std::string ProfessionCreator::get_profession_type() const
{
    return this->type;
}

bool ProfessionCreator::exists(const std::string& type) const
{
    return this->type == type;
}
