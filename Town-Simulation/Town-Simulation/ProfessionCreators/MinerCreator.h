#ifndef MinerCreator_h
#define MinerCreator_h
#include "ProfessionCreator.h"

class MinerCreator : public ProfessionCreator{
public:
    MinerCreator();
    
    Profession* create_profession(const std::string& type) const override;
    
};

#endif /* MinerCreator_h */
