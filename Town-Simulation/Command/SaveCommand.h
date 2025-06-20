#ifndef SaveCommand_h
#define SaveCommand_h

#include "TxtWriter.h"
#include "Command.h"

class SaveCommand : public Command{
public:
    SaveCommand(Simulation* sim);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    Simulation* sim;
};

#endif /* SaveCommand_h */
