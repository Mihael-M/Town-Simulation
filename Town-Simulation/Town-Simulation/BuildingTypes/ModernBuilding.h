#ifndef ModernBuilding_h
#define ModernBuilding_h
#include "Building.h"

class ModernBuilding : public Building{
public:
    // constructors:
    
    ModernBuilding(int capacity);
    
    // functionality:
    
    double calculate_rent() const override;
    double get_base_rent() const override;
    Building* clone() const override;
    
};

#endif /* ModernBuilding_h */
