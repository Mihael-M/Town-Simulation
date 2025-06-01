#include <stdio.h>
#include <stdexcept>
#include "StepsCommand.h"


StepsCommand::StepsCommand(Simulation* sim) : sim(sim) {}

void StepsCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::STEPS_ARGUMENTS)
        throw std::invalid_argument("Not enough information to make steps!");
    int steps = std::atoi(args[0].c_str());
    std::cout<< sim->simulate_days(steps) << std::endl;
}
