#ifndef Location_h
#define Location_h
#include "Constants.hpp"
#include "LocationType.h"

class Location{
public:
    virtual ~Location() = default;
    virtual double rent_multiplier() const = 0;
    virtual LocationType get_type() const = 0;
    virtual Location* clone() const = 0;
};

#endif /* Location_h */
