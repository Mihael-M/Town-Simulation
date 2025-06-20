#ifndef LoadCommand_h
#define LoadCommand_h

#include "Command.h"
#include "TxtReader.h"

class LoadCommand : public Command {
public:
    LoadCommand(Simulation* sim);
    virtual void execute(const std::vector<std::string>& args) override;

private:
    Simulation* sim;
    
};

#endif /* LoadCommand_h */
