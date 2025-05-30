#ifndef Unemployed_h
#define Unemployed_h
#include "Profession.h"

class Unemployed : public Profession{
public:
    Unemployed(std::string& type);
    
    int get_salary() const override;
    
    void monthly_update(Resident* resident) override;
    
    const std::string& get_name() const override;
    
};

#endif /* Unemployed_h */
