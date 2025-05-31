#pragma once
#ifndef PanelBlockBuilding_h
#define PanelBlockBuilding_h
#include "Building.h"
class PanelBlockBuilding : public Building{
private:
    static constexpr double BASE_RENT = Constants::PANEL_BLOCK_BUILDING_RENT;
    
public:
    PanelBlockBuilding(Location* loc,size_t capacity);
    
    double calculate_rent() const override;
    double get_base_rent() const override;
    Building* clone() const override;
};

#endif /* PanelBlockBuilding_h */
