#include <stdio.h>
#include <stdexcept>
#include "BuildingInfoCommand.h"
#include "CityContext.h"

void BuildingInfoCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::BUILDING_INFO_ARGUMENTS)
        throw std::invalid_argument("Not enough information for building information!");
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!context->city_exists())
        throw std::runtime_error("City not created!");
    
    int x = std::atoi(args[0].c_str());
    int y = std::atoi(args[1].c_str());
    
    Building* building = city->get_building_at(x, y);
    if(!building)
        throw std::runtime_error("Building does noe exist!");
    building->print_residents(std::cout);
    building->print_building(std::cout);
}
