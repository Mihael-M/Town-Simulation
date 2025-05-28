#ifndef PanelBlockBuilding_h
#define PanelBlockBuilding_h
#include "Building.h"
class PanelBlockBuilding : public Building{
public:
    // constructors:
    
    PanelBlockBuilding(int capacity);
    
    // functionality:
    
    double calculate_rent() const override;
    double get_base_rent() const override;
    Building* clone() const override;
    
};

#endif /* PanelBlockBuilding_h */
