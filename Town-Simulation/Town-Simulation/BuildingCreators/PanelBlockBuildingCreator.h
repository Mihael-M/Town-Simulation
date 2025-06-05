#ifndef PanelBlockBuildingCreator_h
#define PanelBlockBuildingCreator_h
#include "BuildingCreator.h"

class PanelBlockBuildingCreator : public BuildingCreator{
public:
    PanelBlockBuildingCreator();
    
    virtual Building* create_building(Location* loc) const override;
    
    
};

#endif /* PanelBlockBuildingCreator_h */
