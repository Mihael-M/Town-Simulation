#ifndef ProfessionCreator_h
#define ProfessionCreator_h
#include "Profession.h"

class ProfessionCreator{
public:
    
    ProfessionCreator(std::string type);
    
    std::string get_profession_type() const;
    
    virtual bool exists(std::string& type) const;

    virtual Profession* create_profession(std::string type) const = 0;
    
    virtual ~ProfessionCreator() = default;
    
protected:
        
    std::string type;
};

#endif /* ProfessionCreator_h */
