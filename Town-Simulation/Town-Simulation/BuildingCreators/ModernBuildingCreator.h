#ifndef ModernBuildingCreator_h
#define ModernBuildingCreator_h
#include "BuildingCreator.h"
class ModernBuildingCreator : public BuildingCreator{
public:
    ModernBuildingCreator();
    
    Building* create_building(Location* loc, int capacity) const override;
    
};


#endif /* ModernBuildingCreator_h */
