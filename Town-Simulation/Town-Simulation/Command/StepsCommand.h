#ifndef StepsCommand_h
#define StepsCommand_h

#include "Command.h"
#include "Simulation.h"

class StepsCommand : public Command{
public:
    StepsCommand(Simulation* sim);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    Simulation* sim;
};

#endif /* StepsCommand_h */
