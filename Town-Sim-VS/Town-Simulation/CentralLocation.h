#ifndef CentralLocation_h
#define CentralLocation_h
#include "Location.h"

class CentralLocation : public Location{
public:
    CentralLocation() = default;
    virtual double rent_multiplier() const override;
    virtual Location* clone() const override;
    virtual LocationType get_type() const override;
};

#endif /* CentralLocation_h */
