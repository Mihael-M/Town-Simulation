#ifndef Programmer_h
#define Programmer_h
#include "Profession.h"

class Programmer : public Profession{
public:
    Programmer(const std::string& type);
    
    virtual int get_salary() const override;
    virtual void monthly_update(Resident& resident) override;
    virtual Profession* clone() const override;
};

#endif /* Programmer_h */
