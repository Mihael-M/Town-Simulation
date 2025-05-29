#ifndef Miner_h
#define Miner_h
#include "Profession.h"

namespace MinerSalary{
    constexpr int MAX_SALARY = 3000;
    constexpr int MIN_SALARY = 1000;
};

class Miner : Profession{
public:
    
    int get_salary() const override;
    
    void monthly_update(Resident* resident) override;
    
    std::string get_name() const override;
    
};

#endif /* Miner_h */
