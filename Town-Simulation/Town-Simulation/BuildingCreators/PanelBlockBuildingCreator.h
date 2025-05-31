#ifndef PanelBlockBuildingCreator_h
#define PanelBlockBuildingCreator_h
#include "BuildingCreator.h"

class PanelBlockBuildingCreator : public BuildingCreator{
public:
    PanelBlockBuildingCreator();
    
    Building* create_building(int capacity) const override;
    
    
};

#endif /* PanelBlockBuildingCreator_h */
