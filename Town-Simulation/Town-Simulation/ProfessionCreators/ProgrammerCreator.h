#ifndef ProgrammerCreator_h
#define ProgrammerCreator_h
#include "ProfessionCreator.h"

class ProgrammerCreator : public ProfessionCreator{
public:
    ProgrammerCreator();
    
    Profession* create_profession(std::string type) const override;
};

#endif /* ProgrammerCreator_h */
