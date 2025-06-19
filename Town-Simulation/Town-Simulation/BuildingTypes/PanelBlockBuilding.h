#ifndef PanelBlockBuilding_h
#define PanelBlockBuilding_h
#include "Building.h"
class PanelBlockBuilding : public Building{
private:
    static constexpr double BASE_RENT = Constants::PANEL_BLOCK_BUILDING_RENT;
    
public:
    PanelBlockBuilding(Location* loc);
    
    virtual double calculate_rent() const override;
    virtual double get_base_rent() const override;
    virtual Building* clone() const override;
};

#endif /* PanelBlockBuilding_h */
