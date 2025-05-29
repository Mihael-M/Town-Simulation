#ifndef Teacher_h
#define Teacher_h
#include "Profession.h"

namespace TeacherSalary{
    constexpr int MAX_SALARY = 1300;
    constexpr int MIN_SALARY = 1200;
};

class Teacher : public Profession{
public:
    
    int get_salary() const override;
    
    void monthly_update(Resident* resident) override;
    
    std::string get_name() const override;
    
};

#endif /* Teacher_h */
