#ifndef RemoveResidentCommand_h
#define RemoveResidentCommand_h

#include "Command.h"
#include "ResidentManager.h"
#include "Simulation.h"

class RemoveResidentCommand : public Command{
public:
    RemoveResidentCommand(ResidentManager* manager, Simulation* sim);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    ResidentManager* manager;
    Simulation* sim;
};

#endif /* RemoveResidentCommand_h */
