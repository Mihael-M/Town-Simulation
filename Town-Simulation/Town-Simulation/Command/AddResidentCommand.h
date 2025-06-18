#ifndef AddResidentCommand_h
#define AddResidentCommand_h

#include "Command.h"
#include "ResidentManager.h"
#include "Simulation.h"

class AddResidentCommand : public Command{
public:
    AddResidentCommand(ResidentManager* manager, Simulation* sim);
    
    virtual void execute(const std::vector<std::string> & args);
private:
    ResidentManager* manager;
    Simulation* sim;
};

#endif /* AddResidentCommand_h */
