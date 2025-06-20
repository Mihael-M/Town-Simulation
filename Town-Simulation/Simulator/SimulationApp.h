#ifndef SimulationApp_h
#define SimulationApp_h
#include "CommandProcessor.h"
#include "CommandRegistry.h"
#include "Printer.h"

class SimulationApp{
public:
    static SimulationApp* get_instance(const Printer* printer);
    
    void run();
    
    SimulationApp(const SimulationApp&) = delete;
    
    SimulationApp& operator=(const SimulationApp&) = delete;
    
    void shutdown();
    
    ~SimulationApp();
private:
    static void destroy_instance();
    
    static SimulationApp* theSimulation;
    
    SimulationApp(const Printer* printer);
    
    void free_dynamic();
    
    void menu() const;
    
    
    const Printer* printer;
    
    ResidentManager* manager;
    
    Simulation* sim;
    
    CommandProcessor* processor;
    
    CommandRegistry* registry;
};

#endif /* SimulationApp_h */
