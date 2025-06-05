#include <stdio.h>
#include "ProfessionFactory.h"
#include <stdexcept>

ProfessionFactory* ProfessionFactory::theProfessionFactory = nullptr;

ProfessionFactory* ProfessionFactory::get_factory()
{
    if(theProfessionFactory == nullptr)
        theProfessionFactory = new ProfessionFactory();
    return theProfessionFactory;
}

void ProfessionFactory::register_profession(const ProfessionCreator* creator)
{
    if(count == Constants::MAX_NUMBER_TYPES)
        throw std::out_of_range("No more space for creators!");
    creators[count++] = creator;
}

Profession* ProfessionFactory::create_profession(const std::string& type)
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


const ProfessionCreator* ProfessionFactory::get_creator(const std::string& type) const
{
    for(int i = 0; i < count; i++)
    {
        if(creators[i]->exists(type))
            return creators[i];
    }
    return nullptr;
}
