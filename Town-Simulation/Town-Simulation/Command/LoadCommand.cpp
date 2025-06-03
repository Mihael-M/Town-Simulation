#include <stdio.h>
#include "LoadCommand.h"

LoadCommand::LoadCommand(Simulation* sim) : sim(sim) {}

void LoadCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::LOAD_ARGUMENTS)
        throw std::invalid_argument("Not enough information to load simulation!");
    try {
        std::string fileName = args[0];
        TxtReader reader(fileName);
        reader.read(sim);
    }
    catch(std::runtime_error& error)
    {
        std::cout<<"Error loading simulation: " << error.what() << std::endl;
    }
}

