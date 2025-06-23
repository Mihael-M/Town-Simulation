#ifndef AutoRegisterMiner_hpp
#define AutoRegisterMiner_hpp
#include <stdio.h>
#include "ProfessionFactory.h"

namespace {
    struct AutoRegisterMiner {
        AutoRegisterMiner() {
            ProfessionFactory::get_factory()->register_profession(new MinerCreator());
        }
    };
    static AutoRegisterMiner minerReg;
}


#endif /* AutoRegisterMiner_hpp */
