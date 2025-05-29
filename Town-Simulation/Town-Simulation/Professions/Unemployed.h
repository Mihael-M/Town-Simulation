#ifndef Unemployed_h
#define Unemployed_h
#include "Profession.h"

class Unemployed : public Profession{
public:
    
    int get_salary() const override;
    
    void monthly_update(Resident* resident) override;
    
    std::string get_name() const override;
    
};

#endif /* Unemployed_h */
