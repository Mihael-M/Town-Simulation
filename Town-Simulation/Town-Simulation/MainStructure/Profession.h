#ifndef Profession_h
#define Profession_h
#include <string>

class Resident;

class Profession{
public:
    
    virtual int get_salary() const = 0;
    
    virtual void monthly_update(Resident* resident) = 0;
    
    virtual std::string& get_name() const = 0;
    
    virtual ~Profession() {}
};

#endif /* Profession_h */
