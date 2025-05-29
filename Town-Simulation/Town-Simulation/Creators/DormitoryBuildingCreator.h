#ifndef DormitoryBuildingCreator_h
#define DormitoryBuildingCreator_h
#include "BuildingCreator.h"

class DormitoryBuildingCreator : public BuildingCreator{
public:
    DormitoryBuildingCreator();
    
    Building* create_building(int capacity) const override;
};

#endif /* DormitoryBuildingCreator_h */
