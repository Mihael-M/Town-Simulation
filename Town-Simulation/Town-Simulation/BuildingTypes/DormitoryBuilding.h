#ifndef DormitoryBuilding_h
#define DormitoryBuilding_h
#include "Building.h"

class DormitoryBuilding : public Building{
public:
    // constructors:
    
    DormitoryBuilding(int capacity);
    
    // functionality:
    
    double calculate_rent() const override;
    double get_base_rent() const override;
    Building* clone() const override;
    
};

#endif /* DormitoryBuilding_h */
