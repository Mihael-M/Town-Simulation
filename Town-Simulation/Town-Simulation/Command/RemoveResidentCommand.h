#ifndef RemoveResidentCommand_h
#define RemoveResidentCommand_h

#include "Command.h"
#include "ResidentManager.h"

class RemoveResidentCommand : public Command{
public:
    RemoveResidentCommand(ResidentManager* manager);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    ResidentManager* manager;
};

#endif /* RemoveResidentCommand_h */
