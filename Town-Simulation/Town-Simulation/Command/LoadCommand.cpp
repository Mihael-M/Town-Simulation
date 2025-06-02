#include <stdio.h>
#include "LoadCommand.h"
#include "Simulation.h"

void LoadCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::LOAD_ARGUMENTS)
        throw std::invalid_argument("Not enough information to load simulation!");
    
    // load logic!!
}

