#ifndef AddResidentCommand_h
#define AddResidentCommand_h

#include "Command.h"
#include "ResidentManager.h"

class AddResidentCommand : public Command{
public:
    AddResidentCommand(ResidentManager* manager);
    
    virtual void execute(const std::vector<std::string> & args);
private:
    ResidentManager* manager;
};

#endif /* AddResidentCommand_h */
