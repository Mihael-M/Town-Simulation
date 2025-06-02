#ifndef LoadCommand_h
#define LoadCommand_h

#include "Command.h"
#include "TxtReader.h"

class LoadCommand : public Command {
public:
    
    virtual void execute(const std::vector<std::string>& args) override;

    
};

#endif /* LoadCommand_h */
