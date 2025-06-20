#include <stdio.h>
#include <stdexcept>
#include "ResidentInfoCommand.h"
#include "CityContext.h"

ResidentInfoCommand::ResidentInfoCommand(ResidentManager* manager) : manager(manager) {}


void ResidentInfoCommand::execute(const std::vector<std::string>& args)
{
        int x = std::atoi(args[0].c_str());
        int y = std::atoi(args[1].c_str());
    
    if(!is_number(args[0]) || !is_number(args[1]))
        throw std::invalid_argument("Invalid symbols.");
    
    try{
        Coordinates coords(x, y);
        
        std::string name = args[2];
        
        manager->print_resident(coords, name);
    }
    catch(std::invalid_argument& err)
    {
        std::cout<<"Error getting resident info: " << err.what() << std::endl;
    }
    catch(...)
    {
        std::cout<<"Error getting resident info!" << std::endl;
    }
}
