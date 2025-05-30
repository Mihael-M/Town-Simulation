#ifndef Profession_h
#define Profession_h
#include <string>

class Resident;

class Profession{
public:
    Profession(std::string name) : name(std::move(name)) {}
    
    virtual int get_salary() const = 0;
    
    virtual void monthly_update(Resident* resident) = 0;
    
    virtual const std::string& get_name() const = 0;
    
    virtual ~Profession() {}
    
protected:
    std::string name;
};

#endif /* Profession_h */
