#include <stdio.h>
#include "BuildingFactory.h"

BuildingFactory& BuildingFactory::get_factory()
{
    static BuildingFactory theFactory;
    return theFactory;
}

void BuildingFactory::register_building(const BuildingCreator* creator)
{
    if(count < MaxNumberTypes)
        creators[count++] = creator;
}

Building* BuildingFactory::create_building(BuildingType type, int capacity)
{

    const BuildingCreator* creator = get_creator(type);
    
    if (creator) {
        return creator->create_building(capacity);
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
