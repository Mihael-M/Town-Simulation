#include <stdio.h>
#include <stdexcept>
#include "ResidentInfoCommand.h"
#include "CityContext.h"

void ResidentInfoCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::RESIDENT_INFO_ARGUMENTS)
        throw std::invalid_argument("Not enough information to get a resident!");
    
        CityContext* context = CityContext::get_instance();
        City* city = context->get_city();
        if(!context->city_exists())
            throw std::runtime_error("City not created!");
        
        int x = std::atoi(args[0].c_str());
        int y = std::atoi(args[1].c_str());
        
    try{
        Building* building = city->get_building_at(x, y);
        
        std::string name = args[2];
        
        building->print_resident(name);
    }
    catch(std::invalid_argument& err)
    {
        std::cout<<"Error getting resident info: " << err.what() << std::endl;
    }
}
