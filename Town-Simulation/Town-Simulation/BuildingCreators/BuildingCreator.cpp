#include <stdio.h>
#include "BuildingCreator.h"

BuildingCreator::BuildingCreator(const BuildingType type) : type(type) {}

BuildingType BuildingCreator::get_type() const
{
    return type;
}

bool BuildingCreator::exists(BuildingType type) const
{
    return this->type == type;
}
