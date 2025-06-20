#ifndef AutoRegisterTeacher_hpp
#define AutoRegisterTeacher_hpp

#include <stdio.h>
#include "ProfessionFactory.h"

namespace {
    struct AutoRegisterTeacher {
        AutoRegisterTeacher() {
            ProfessionFactory::get_factory()->register_profession(new TeacherCreator());
        }
    };
    static AutoRegisterTeacher teacherReg;
}

#endif /* AutoRegisterTeacher_hpp */
