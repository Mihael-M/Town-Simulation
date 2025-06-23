#ifndef AutoRegisterDormitory_hpp
#define AutoRegisterDormitory_hpp

#include <stdio.h>

#include "BuildingFactory.h"

namespace {
    struct AutoRegisterDormitory {
        AutoRegisterDormitory() {
            BuildingFactory::get_factory()->register_building(new DormitoryBuildingCreator());
        }
    };
    static AutoRegisterDormitory dormitoryReg;
}

#endif /* AutoRegisterDormitory_hpp */
