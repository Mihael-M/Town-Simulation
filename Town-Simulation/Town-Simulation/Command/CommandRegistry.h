#ifndef CommandRegistry_h
#define CommandRegistry_h


#include "CommandProcessor.h"
#include "Simulation.h"

class CommandRegistry {
public:
    CommandRegistry(Simulation* sim, ResidentManager* manager);
    void register_all_commands(CommandProcessor& processor);
private:
    Simulation* sim;
    ResidentManager* manager;
};
#endif /* CommandRegistry_h */
