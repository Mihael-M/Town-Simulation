#ifndef ProgrammerCreator_h
#define ProgrammerCreator_h
#include "ProfessionCreator.h"

class ProgrammerCreator : public ProfessionCreator{
public:
    ProgrammerCreator();
    
    virtual Profession* create_profession(const std::string& type) const override;
};

#endif /* ProgrammerCreator_h */
