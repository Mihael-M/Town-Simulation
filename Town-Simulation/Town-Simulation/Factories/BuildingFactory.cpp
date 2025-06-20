#include <stdio.h>
#include "BuildingFactory.h"


BuildingFactory* BuildingFactory::theBuildingFactory = nullptr;

BuildingFactory* BuildingFactory::get_factory()
{
    if(theBuildingFactory == nullptr)
        theBuildingFactory =  new BuildingFactory();
    return theBuildingFactory;
}

void BuildingFactory::register_building(const BuildingCreator* creator)
{
    if(count < Constants::MAX_NUMBER_TYPES)
        creators[count++] = creator;
}

Building* BuildingFactory::create_building(BuildingType type, Location* loc)
{

    const BuildingCreator* creator = get_creator(type);
    
    if (creator) {
        return creator->create_building(loc);
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

void BuildingFactory::delete_creators()
{
    for(int i = 0;i < count;i++)
    {
        delete creators[i];
    }
}

BuildingFactory::~BuildingFactory()
{
    delete_creators();
   
}

void BuildingFactory::destroy_instance()
{
    delete theBuildingFactory;
    theBuildingFactory = nullptr;
}
