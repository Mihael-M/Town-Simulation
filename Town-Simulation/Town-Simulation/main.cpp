#include "SimulationApp.h"

int main() {
    SimulationApp* simulation = SimulationApp::get_instance();
    simulation->run();
    return 0;
}
