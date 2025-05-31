#include "PeripheralLocation.h"

double PeripheralLocation::rent_multiplier() const{
    return Constants::PERIPHERAL_LOCATION_RENT_MULTIPLIER;
}

Location* PeripheralLocation::clone() const{
    return new PeripheralLocation(*this);
}
