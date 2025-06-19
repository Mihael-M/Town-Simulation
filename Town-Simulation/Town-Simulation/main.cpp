#include "SimulationApp.h"
#include "ResidentEditor.h"

int main() {
    SimulationApp* simulation = SimulationApp::get_instance();
    simulation->run();
    delete simulation;
    return 0;
}
