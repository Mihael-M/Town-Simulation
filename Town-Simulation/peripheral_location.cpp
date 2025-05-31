#include "peripheral_location.h"

double peripheral_location::rent_multiplier() const{
    return Constants::PERIPHERAL_LOCATION_RENT_MULTIPLIER;
}

location* peripheral_location::clone() const{
    return new peripheral_location(*this);
}
