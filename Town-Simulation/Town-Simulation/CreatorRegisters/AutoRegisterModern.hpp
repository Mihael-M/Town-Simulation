#ifndef AutoRegisterModern_hpp
#define AutoRegisterModern_hpp
#include <stdio.h>

#include "BuildingFactory.h"

namespace {
    struct AutoRegisterModern {
        AutoRegisterModern() {
            BuildingFactory::get_factory()->register_building(new ModernBuildingCreator());
        }
    };
    static AutoRegisterModern modernReg;
}

#endif /* AutoRegisterModern_hpp */
