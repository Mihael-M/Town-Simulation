#include <stdio.h>
#include <stdexcept>
#include "BuildingInfoCommand.h"
#include "CityContext.h"

void BuildingInfoCommand::execute(const std::vector<std::string>& args)
{
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!context->city_exists())
        throw std::runtime_error("City not created!");
    
    int x = std::atoi(args[0].c_str());
    int y = std::atoi(args[1].c_str());
    
    if(!is_number(args[0]) || !is_number(args[1]))
        throw std::invalid_argument("Invalid symbols.");
    
    try{
        
        Coordinates coords(x, y);
        Building* building = city->get_building_at(coords);
        if(!building)
            throw std::runtime_error("Building does noe exist!");
        building->print_residents(std::cout);
        building->print_building(std::cout);
    }
    catch(std::invalid_argument& error)
    {
        std::cout<<"Error getting building info: " << error.what() << std::endl;
    }
    catch(std::runtime_error& error)
    {
        std::cout<<"Error getting building info: " << error.what() << std::endl;
    }
}
