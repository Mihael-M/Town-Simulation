#ifndef Programmer_h
#define Programmer_h
#include "Profession.h"

namespace ProgrammerSalary{
    constexpr int MAX_SALARY = 5000;
    constexpr int MIN_SALARY = 2000;
};

class Programmer : public Profession{
public:
    
    int get_salary() const override;
    
    void monthly_update(Resident* resident) override;
    
    std::string get_name() const override;
    
};

#endif /* Programmer_h */
