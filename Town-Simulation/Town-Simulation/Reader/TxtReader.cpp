#include <stdio.h>
#include "TxtReader.h"
#include "CityContext.h"
#include "LocationFactory.h"
#include "BuildingFactory.h"
#include <fstream>

TxtReader::TxtReader(const std::string& fileName) : Reader(fileName) {}

void TxtReader::read(Simulation* sim)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("File could not be foundgg!");

    sim->load_simulation_from_file(file);
    
    file.close();
}
