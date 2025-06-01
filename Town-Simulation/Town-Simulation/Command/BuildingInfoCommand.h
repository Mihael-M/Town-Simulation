#ifndef BuildingInfoCommand_h
#define BuildingInfoCommand_h

#include "Command.h"

class BuildingInfoCommand : public Command{
public:
    
    virtual void execute(const std::vector<std::string>& args) override;
    
}

#endif /* BuildingInfoCommand_h */
