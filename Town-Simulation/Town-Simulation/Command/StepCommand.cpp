#include <stdio.h>
#include <stdexcept>
#include "StepCommand.h"

StepCommand::StepCommand(Simulation* sim) : sim(sim) {}

void StepCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::STEP_ARGUMENTS)
        throw std::invalid_argument("Wrong arguments for step!");
    try{
        std::cout<< sim->simulate_day() << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout<<"Error step from: " << ex.what() << std::endl;
    }
}
