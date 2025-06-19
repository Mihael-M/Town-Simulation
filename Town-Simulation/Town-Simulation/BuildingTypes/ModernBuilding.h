#ifndef ModernBuilding_h
#define ModernBuilding_h
#include "Building.h"

class ModernBuilding : public Building{
private:
    static constexpr double BASE_RENT = Constants::MODERN_BUILDING_RENT;
    
public:
    
    ModernBuilding(Location* loc);
    
    virtual double calculate_rent() const override;
    virtual double get_base_rent() const override;
    virtual Building* clone() const override;
    
};

#endif /* ModernBuilding_h */
