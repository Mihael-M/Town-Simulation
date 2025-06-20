#ifndef AutoRegisterProgrammer_hpp
#define AutoRegisterProgrammer_hpp

#include <stdio.h>

#include "ProfessionFactory.h"

namespace {
    struct AutoRegisterProgrammer {
        AutoRegisterProgrammer() {
            ProfessionFactory::get_factory()->register_profession(new ProgrammerCreator());
        }
    };
    static AutoRegisterProgrammer programmerReg;
}

#endif /* AutoRegisterProgrammer_hpp */
