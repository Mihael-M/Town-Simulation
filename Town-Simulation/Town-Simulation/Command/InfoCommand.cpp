#include <stdio.h>
#include "InfoCommand.h"
#include <stdexcept>

InfoCommand::InfoCommand(Simulation* sim) : sim(sim) {}

void InfoCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::INFO_ARGUMENTS)
        throw std::invalid_argument("Wrong arguments for info!");
    
    sim->print_status(std::cout);
}

