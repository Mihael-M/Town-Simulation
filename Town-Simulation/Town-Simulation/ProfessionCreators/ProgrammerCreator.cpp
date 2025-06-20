#include <stdio.h>
#include "ProgrammerCreator.h"
#include "Programmer.h"

ProgrammerCreator::ProgrammerCreator() : ProfessionCreator("Programmer") {}

Profession* ProgrammerCreator::create_profession(const std::string& type) const
{
    return new Programmer(type);
}

