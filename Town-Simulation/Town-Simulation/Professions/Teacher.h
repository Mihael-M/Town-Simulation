#ifndef Teacher_h
#define Teacher_h
#include "Profession.h"

class Teacher : public Profession{
public:
    Teacher(const std::string& type);
    
    virtual int get_salary() const override;
    virtual void monthly_update(Resident* resident) override;
    virtual Profession* clone() const override;
};

#endif /* Teacher_h */
