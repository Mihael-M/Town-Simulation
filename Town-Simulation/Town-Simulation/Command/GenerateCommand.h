#ifndef GenerateCommand_h
#define GenerateCommand_h

#include "Command.h"
#include "City.h"

class GenerateCommand : public Command{
public:
    
    GenerateCommand(City* city);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    City* city;
    
};



#endif /* GenerateCommand_h */
