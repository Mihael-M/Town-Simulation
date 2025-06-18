#include <stdio.h>
#include <stdexcept>
#include "RemoveResidentCommand.h"
#include "CityContext.h"

RemoveResidentCommand::RemoveResidentCommand(ResidentManager* manager, Simulation* sim) : manager(manager), sim(sim) {}

void RemoveResidentCommand::execute(const std::vector<std::string>& args)
{
    
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    
    if(!context->city_exists())
        throw std::runtime_error("City not created!");
    
    int x = std::atoi(args[0].c_str());
    int y = std::atoi(args[1].c_str());
    try{
        Coordinates coords(x, y);
        Building* building = city->get_building_at(coords);
        if(!building)
            throw std::runtime_error("No building found at specified coordinates!");
    
        std::string name = args[2];
    
    
        manager->remove_resident(building, name, sim->get_current_day());
        
        
        std::cout<<"Resident removed successfully." << std::endl;
    }
    catch(std::exception& ex){
        std::cout<<"Error with removing the resident: " << ex.what() << std::endl;
    }
    
}
