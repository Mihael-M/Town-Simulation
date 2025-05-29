#ifndef BuildingFactory_h
#define BuildingFactory_h
#include "BuildingType.h"
#include "BuildingCreator.h"

class BuildingFactory{
public:
    // Тя ще е сингълтон.
    static BuildingFactory& get_factory();
    
    void register_building(const BuildingCreator* creator);

    // Метод фабрика
    Building* create_building(BuildingType type, int capacity);

private:
    // Метод за търсене на подходяща фабрика
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
