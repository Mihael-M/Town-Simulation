#pragma once
#ifndef ModernBuilding_h
#define ModernBuilding_h
#include "Building.h"

class ModernBuilding : public Building{
private:
    static constexpr double BASE_RENT = Constants::MODERN_BUILDING_RENT;
    
public:
    
    ModernBuilding(location* loc,size_t capacity = Constants::DEFAULT_INITIAL_RESIDENTS);
    
    double calculate_rent() const override;
    double get_base_rent() const override;
    Building* clone() const override;
    
};

#endif /* ModernBuilding_h */
