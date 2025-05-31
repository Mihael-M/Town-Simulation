#ifndef Unemployed_h
#define Unemployed_h
#include "Profession.h"

class Unemployed : public Profession{
public:
    Unemployed(std::string& type);
    
    virtual int get_salary() const override;
    virtual void monthly_update(Resident* resident) override;
    virtual Profession* clone() const override;
};

#endif /* Unemployed_h */
