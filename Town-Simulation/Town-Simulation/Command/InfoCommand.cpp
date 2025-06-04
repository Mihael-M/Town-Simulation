#include <stdio.h>
#include "InfoCommand.h"
#include <stdexcept>

InfoCommand::InfoCommand(Simulation* sim) : sim(sim) {}

void InfoCommand::execute(const std::vector<std::string>& args)
{
    try{
        sim->print_status(std::cout);
    }
    catch(std::exception& ex)
    {
        std::cout<<"Error from info: " << ex.what() << std::endl;
    }
}

