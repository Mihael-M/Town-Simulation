#include <stdio.h>
#include "TeacherCreator.h"
#include "Teacher.h"

TeacherCreator::TeacherCreator() : ProfessionCreator("Teacher") {}

Profession* TeacherCreator::create_profession(std::string type) const
{
    return new Teacher(type);
}
