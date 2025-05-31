#include <stdio.h>
#include "BuildingFactory.h"

BuildingFactory& BuildingFactory::get_factory()
{
    static BuildingFactory theBuildingFactory;
    return theBuildingFactory;
}

void BuildingFactory::register_building(const BuildingCreator* creator)
{
    if(count < Constants::MAX_NUMBER_TYPES)
        creators[count++] = creator;
}

Building* BuildingFactory::create_building(BuildingType type, Location* loc, int capacity)
{

    const BuildingCreator* creator = get_creator(type);
    
    if (creator) {
        return creator->create_building(loc, capacity);
    }
    else {
        return nullptr;
    }
}

const BuildingCreator* BuildingFactory::get_creator(BuildingType type) const
{
    for (int i = 0; i < count; ++i)
        if (creators[i]->exists(type))
            return creators[i];

    return nullptr;
}
