#ifndef AutoRegisterUnemployed_hpp
#define AutoRegisterUnemployed_hpp

#include <stdio.h>

#include "ProfessionFactory.h"

namespace {
    struct AutoRegisterUnemployed {
        AutoRegisterUnemployed() {
            ProfessionFactory::get_factory()->register_profession(new UnemployedCreator());
        }
    };
    static AutoRegisterUnemployed unemployedReg;
}

#endif /* AutoRegisterUnemployed_hpp */
