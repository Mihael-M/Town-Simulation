#ifndef DormitoryBuildingCreator_h
#define DormitoryBuildingCreator_h
#include "BuildingCreator.h"

class DormitoryBuildingCreator : public BuildingCreator{
public:
    DormitoryBuildingCreator();
    
    virtual Building* create_building(Location* loc) const override;
};

#endif /* DormitoryBuildingCreator_h */
