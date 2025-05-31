#ifndef UnemployedCreator_h
#define UnemployedCreator_h
#include "ProfessionCreator.h"

class UnemployedCreator : public ProfessionCreator{
public:
    
    UnemployedCreator();
    
    virtual Profession* create_profession(const std::string& type) const override;
    
};

#endif /* UnemployedCreator_h */
