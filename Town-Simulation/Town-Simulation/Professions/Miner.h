#ifndef Miner_h
#define Miner_h
#include "Profession.h"


class Miner : public Profession{
public:
    Miner(const std::string& type);
    
    virtual int get_salary() const override;
    virtual void monthly_update(Resident& resident) override;
    virtual Profession* clone() const override;
};

#endif /* Miner_h */
