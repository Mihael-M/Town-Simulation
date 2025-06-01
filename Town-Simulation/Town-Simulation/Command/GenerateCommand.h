#ifndef GenerateCommand_h
#define GenerateCommand_h

#include "Command.h"
#include "City.h"
#include "CityContext.h"
#include "Simulation.h"
#include "ResidentManager.h"

class GenerateCommand : public Command{
public:
    
    GenerateCommand(Simulation* sim);
    
    virtual void execute(const std::vector<std::string>& args) override;
    
private:
    
    Simulation* sim;
    
};



#endif /* GenerateCommand_h */
