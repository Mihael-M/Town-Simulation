#include <stdio.h>
#include <ctime>
#include "GenerateCommand.h"

GenerateCommand::GenerateCommand(Simulation* sim) : sim(sim) {}

void GenerateCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::GENERATE_CITY_ARGUMENTS)
        throw std::invalid_argument("Not enough information for generate command!");
    CityContext* cityContext = CityContext::get_instance();
    
    City* city = cityContext->get_city();
    
    int width = std::atoi(args[0].c_str());
    int height = std::atoi(args[1].c_str());
    
    if(cityContext->city_exists())
        delete city;
    cityContext->set_city(new City(width, height));
    
    sim->add_to_history(*cityContext->get_city());
    
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    std::cout<< buffer << std::endl;
}

