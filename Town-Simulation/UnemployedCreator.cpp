#include <stdio.h>
#include "UnemployedCreator.h"
#include "Unemployed.h"

UnemployedCreator::UnemployedCreator() : ProfessionCreator("Unemployed") {}

Profession* UnemployedCreator::create_profession(std::string& type) const
{
    return new Unemployed(type);
}
