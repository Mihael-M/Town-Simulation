#ifndef ResidentInfoCommand_h
#define ResidentInfoCommand_h

#include "Command.h"
#include "ResidentManager.h"

class ResidentInfoCommand : public Command{
public:
    ResidentInfoCommand(ResidentManager* manager);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    ResidentManager* manager;
};

#endif /* ResidentInfoCommand_h */
