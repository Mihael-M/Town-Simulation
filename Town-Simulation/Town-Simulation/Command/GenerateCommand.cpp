#include <stdio.h>
#include <ctime>
#include "GenerateCommand.h"

GenerateCommand::GenerateCommand(City* city) : city(city) {}

void GenerateCommand::execute(const std::vector<std::string>& args)
{
    if(args.size() != 2)
        throw std::invalid_argument("Not enough information for generate command!");
    int width = std::atoi(args[0].c_str());
    int height = std::atoi(args[1].c_str());
    delete city;
    city = new City(width, height);
    
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    std::cout<< buffer << std::endl;
}

