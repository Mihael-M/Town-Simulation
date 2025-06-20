#ifndef TeacherCreator_h
#define TeacherCreator_h
#include "ProfessionCreator.h"

class TeacherCreator : public ProfessionCreator{
public:
    TeacherCreator();
    
    virtual Profession* create_profession(const std::string& type) const override;
    
};

#endif /* TeacherCreator_h */
