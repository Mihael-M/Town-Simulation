#include <stdio.h>
#include <stdexcept>
#include "StepsCommand.h"


StepsCommand::StepsCommand(Simulation* sim) : sim(sim) {}

void StepsCommand::execute(const std::vector<std::string>& args)
{
    int steps = std::atoi(args[0].c_str());
    try{
        int removed = sim->simulate_days(steps);
        if(removed != -1)
            std::cout<< " " << removed << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout<<"Error from steps command: " << ex.what() << std::endl;
    }
}
