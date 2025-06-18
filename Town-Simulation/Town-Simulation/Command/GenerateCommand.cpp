#include <stdio.h>
#include <ctime>
#include "GenerateCommand.h"

GenerateCommand::GenerateCommand(Simulation* sim) : sim(sim) {}

void GenerateCommand::execute(const std::vector<std::string>& args)
{
    int width = std::atoi(args[0].c_str());
    int height = std::atoi(args[1].c_str());
    
    sim->generate_city(width, height);
    
    std::cout<<sim->get_date()<<std::endl;
}

