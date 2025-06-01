#ifndef StepCommand_h
#define StepCommand_h

#include "Command.h"
#include "Simulation.h"

class StepCommand : public Command{
public:
    StepCommand(Simulation* sim);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    Simulation* sim;
};

#endif /* StepCommand_h */
