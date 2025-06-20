#include "SimulationApp.h"
#include "ConsolePrinter.hpp"

int main() {
    Printer* printer = new ConsolePrinter();
    SimulationApp* simulation = SimulationApp::get_instance(printer);
    simulation->run();
    simulation->shutdown();
    return 0;
}
