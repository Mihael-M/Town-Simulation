#ifndef AutoRegisterPanelBlock_hpp
#define AutoRegisterPanelBlock_hpp

#include <stdio.h>
#include "BuildingFactory.h"

namespace {
    struct AutoRegisterPanelBlock {
        AutoRegisterPanelBlock() {
            BuildingFactory::get_factory()->register_building(new PanelBlockBuildingCreator());
        }
    };
    static AutoRegisterPanelBlock panelReg;
}

#endif /* AutoRegisterPanelBlock_hpp */
