#include <stdio.h>
#include "ProfessionFactory.h"


ProfessionFactory& ProfessionFactory::get_factory()
{
    static ProfessionFactory theProfessionFactory;
    return theProfessionFactory;
}

void ProfessionFactory::register_profession(const ProfessionCreator* creator)
{
    if(count < Constants::MAX_NUMBER_TYPES)
        creators[count++] = creator;
}

Profession* ProfessionFactory::create_profession(std::string& type)
{
    const ProfessionCreator* creator = get_creator(type);
    
    if(creator)
    {
        return creator->create_profession(type);
    }
    else{
        return nullptr;
    }
}


const ProfessionCreator* ProfessionFactory::get_creator(std::string& type) const
{
    for(int i = 0; i < count; i++)
    {
        if(creators[i]->exists(type))
            return creators[i];
    }
    return nullptr;
}
