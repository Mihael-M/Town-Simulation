#ifndef DormitoryBuilding_h
#define DormitoryBuilding_h
#include "Building.h"

class DormitoryBuilding : public Building{
private:
    static constexpr double BASE_RENT = Constants::DORMITORY_BUILDING_RENT;
    
public:
    
    DormitoryBuilding(Location* loc);
    
    virtual double calculate_rent() const override;
    virtual double get_base_rent() const override;
    virtual Building* clone() const override;
    
};

#endif /* DormitoryBuilding_h */
