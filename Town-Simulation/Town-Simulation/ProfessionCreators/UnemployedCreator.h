#ifndef UnemployedCreator_h
#define UnemployedCreator_h
#include "ProfessionCreator.h"

class UnemployedCreator : public ProfessionCreator{
public:
    
    UnemployedCreator();
    
    Profession* create_profession(const std::string& type) const override;
    
};

#endif /* UnemployedCreator_h */
