#include <stdio.h>
#include <stdexcept>
#include "AddResidentCommand.h"
#include "ProfessionFactory.h"
#include "CityContext.h"

AddResidentCommand::AddResidentCommand(ResidentManager* manager) : manager(manager) {}

void AddResidentCommand::execute(const std::vector<std::string> & args)
{
    if (args.size() != Constants::ADD_RESIDENT_ARGUMENTS)
        throw std::invalid_argument("Not enough information to add a resident!");
    
    ProfessionFactory* factory = ProfessionFactory::get_factory();
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    
    if(!context->city_exists())
        throw std::runtime_error("City not created!");
    
    
    int x = std::atoi(args[0].c_str());
    int y = std::atoi(args[1].c_str());
    
    Building* building = city->get_building_at(x, y);
    if(!building)
        throw std::runtime_error("No building found at specified coordinates!");
    
    int happiness = std::atoi(args[4].c_str());
    double money = std::stod(args[5].c_str());
    int life_points = std::atoi(args[6].c_str());
    std::string name = args[2];
    std::string professionType = args[3];
    
    resident_info info(happiness, money, life_points);
    
    Profession* profession = factory->create_profession(professionType);
    
    Resident* resident = new Resident(name, info, profession);
    
    manager->addResident(city, x, y, resident);
    
    std::cout<<"Resident added successfully."<<std::endl;
}
