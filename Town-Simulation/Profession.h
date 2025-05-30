#ifndef Profession_h
#define Profession_h
#include <string>
#include "Constants.hpp"


class Resident;

class Profession{
public:
    Profession(const std::string& type);
    
    virtual int get_salary() const = 0;
    
    virtual void monthly_update(Resident* resident) = 0;
    
    const std::string& get_type() const;
    
    virtual ~Profession() = default;
    virtual Profession* clone() const = 0;
    
protected:
    std::string type;
};

#endif /* Profession_h */
