#include <stdio.h>
#include <ctime>
#include "GenerateCommand.h"

GenerateCommand::GenerateCommand(Simulation* sim) : sim(sim) {}

void GenerateCommand::execute(const std::vector<std::string>& args)
{
    int width = std::atoi(args[0].c_str());
    int height = std::atoi(args[1].c_str());
    
    if(!is_number(args[0]) || !is_number(args[1]))
        throw std::invalid_argument("Invalid symbols.");
    
    sim->generate_city(width, height);
    
    std::cout<<sim->get_date()<<std::endl;
}

