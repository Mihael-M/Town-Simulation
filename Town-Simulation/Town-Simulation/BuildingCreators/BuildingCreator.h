#ifndef BuildingCreator_h
#define BuildingCreator_h
#include "Building.h"

class BuildingCreator{
public:
    BuildingCreator(const BuildingType type);
    
    BuildingType get_type() const;
    
    virtual Building* create_building(int capacity) const = 0;
    
    virtual bool exists(BuildingType type) const;
        
    
    virtual ~BuildingCreator() = default;

protected:
    BuildingType type;
};

#endif /* BuildingCreator_h */
