#ifndef BuildingFactory_h
#define BuildingFactory_h
#include "DormitoryBuildingCreator.h"
#include "ModernBuildingCreator.h"
#include "PanelBlockBuildingCreator.h"


class BuildingFactory{
public:
    // Singleton
    static BuildingFactory& get_factory();
    
    void register_building(const BuildingCreator* creator);

    // Factory method
    Building* create_building(BuildingType type, int capacity);

private:
    // Search method
    const BuildingCreator* get_creator(BuildingType type) const;

private:
    BuildingFactory() : count(0) {};
    
    ~BuildingFactory() = default;
    
    BuildingFactory(const BuildingFactory&) = delete;
    
    BuildingFactory& operator=(const BuildingFactory&) = delete;

private:
    static const int MaxNumberTypes = 10;

    const BuildingCreator* creators[MaxNumberTypes];
    int count;
    
    
};



#endif /* BuildingFactory_h */
