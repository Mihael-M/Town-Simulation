#include <stdio.h>
#include "TxtWriter.h"
#include <fstream>
#include <stdexcept>

TxtWriter::TxtWriter(const std::string& fileName) : Writer(fileName) {}

void TxtWriter::write(Simulation* sim) const
{
    if(!sim)
        return;
    std::ofstream ofs;
    ofs.open(fileName);
    if(!ofs)
        throw std::runtime_error("File could not open!");
    sim->save_simulation_to_file(ofs);
    ofs.close();
}
