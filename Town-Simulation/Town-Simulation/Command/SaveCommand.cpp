#include <stdio.h>
#include "SaveCommand.h"


SaveCommand::SaveCommand(Simulation* sim) : sim(sim) {}

void SaveCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != Constants::SAVE_ARGUMENTS)
        throw std::invalid_argument("Not enough information to save simulation!");
    try{
        std::string fileName = args[0];
        TxtWriter writer(fileName);
        writer.write(sim);
    }
    catch(std::runtime_error& error)
    {
        std::cout<<"Error with file: " << error.what() << std::endl;
    }
}
