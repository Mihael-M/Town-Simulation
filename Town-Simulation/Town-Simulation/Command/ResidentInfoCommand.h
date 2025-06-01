#ifndef ResidentInfoCommand_h
#define ResidentInfoCommand_h

#include "Command.h"

class ResidentInfoCommand : public Command{
public:
    
    virtual void execute(const std::vector<std::string>& args) override;
    
};

#endif /* ResidentInfoCommand_h */
