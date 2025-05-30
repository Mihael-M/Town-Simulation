#ifndef TeacherCreator_h
#define TeacherCreator_h
#include "ProfessionCreator.h"

class TeacherCreator : public ProfessionCreator{
public:
    TeacherCreator();
    
    Profession* create_profession(std::string type) const override;
    
};

#endif /* TeacherCreator_h */
