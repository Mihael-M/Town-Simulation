#include <stdio.h>
#include <stdexcept>
#include "AddResidentCommand.h"
#include "ProfessionFactory.h"
#include "CityContext.h"

AddResidentCommand::AddResidentCommand(ResidentManager* manager, Simulation* sim) : manager(manager), sim(sim) {}

void AddResidentCommand::execute(const std::vector<std::string> & args)
{
    ProfessionFactory* factory = ProfessionFactory::get_factory();
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    
    if(!context->city_exists())
        throw std::runtime_error("City not created!");
    
    
    int x = std::atoi(args[0].c_str());
    int y = std::atoi(args[1].c_str());
    Coordinates coords(x, y);
    Building* building = city->get_building_at(coords);
    if(!building)
        throw std::runtime_error("No building found at specified coordinates!");
    
    int happiness = std::atoi(args[4].c_str());
    double money = std::stod(args[5].c_str());
    int life_points = std::atoi(args[6].c_str());
    std::string name = args[2];
    std::string professionType = args[3];
    
    resident_info* info = new resident_info(coords,sim->get_current_day(), happiness, money, life_points);
    
    Profession* profession = factory->create_profession(professionType);
    
    Resident* resident = new Resident(info, name, profession);
    try{
        manager->add_resident(building, resident);
        
        std::cout<<"Resident added successfully."<<std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout<<"Error adding the  resident from: " << ex.what() << std::endl;
    }
}
