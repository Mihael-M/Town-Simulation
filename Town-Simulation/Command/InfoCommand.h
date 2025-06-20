#ifndef InfoCommand_h
#define InfoCommand_h

#include "Command.h"
#include "Simulation.h"
class InfoCommand : public Command{
public:
    InfoCommand(Simulation* sim);
  
    virtual void execute(const std::vector<std::string>& args) override;
private:
    Simulation* sim;
};

#endif /* InfoCommand_h */
