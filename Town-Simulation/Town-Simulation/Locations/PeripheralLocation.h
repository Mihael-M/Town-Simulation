#ifndef PeripheralLocation_h
#define PeripheralLocation_h

#include "Location.h"


class PeripheralLocation : public Location {
public:
    PeripheralLocation() = default;
    virtual double rent_multiplier() const override;
    virtual Location* clone() const override;
    virtual LocationType get_type() const override;
};
#endif /* PeripheralLocation_h */
