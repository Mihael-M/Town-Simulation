#ifndef BuildingFactory_h
#define BuildingFactory_h
#include "DormitoryBuildingCreator.h"
#include "ModernBuildingCreator.h"
#include "PanelBlockBuildingCreator.h"
#include "Constants.hpp"

class BuildingFactory{
public:
    static BuildingFactory* get_factory();
    
    void register_building(const BuildingCreator* creator);

    Building* create_building(BuildingType type, Location* loc);

    static void destroy_instance();
    
private:
    const BuildingCreator* get_creator(BuildingType type) const;

private:
    void delete_creators();
    
    BuildingFactory() : count(0) {}
    
    ~BuildingFactory();
    
    BuildingFactory(const BuildingFactory& other) = delete;
    
    BuildingFactory& operator=(const BuildingFactory& other) = delete;

private:
    static BuildingFactory* theBuildingFactory;
    const BuildingCreator* creators[Constants::MAX_NUMBER_TYPES];
    int count;
};



#endif /* BuildingFactory_h */
