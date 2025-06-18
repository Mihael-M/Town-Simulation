#ifndef ModernBuildingCreator_h
#define ModernBuildingCreator_h
#include "BuildingCreator.h"
class ModernBuildingCreator : public BuildingCreator{
public:
    ModernBuildingCreator();
    
    virtual Building* create_building(Location* loc) const override;
    
};


#endif /* ModernBuildingCreator_h */
