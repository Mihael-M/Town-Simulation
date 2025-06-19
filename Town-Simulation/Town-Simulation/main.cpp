#include "SimulationApp.h"

int main() {
    SimulationApp* simulation = SimulationApp::get_instance();
    simulation->run();
    simulation->shutdown();
    return 0;
}
