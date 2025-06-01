#include "PeripheralLocation.h"
#include "LocationType.h"

double PeripheralLocation::rent_multiplier() const{
    return Constants::PERIPHERAL_LOCATION_RENT_MULTIPLIER;
}

Location* PeripheralLocation::clone() const{
    return new PeripheralLocation(*this);
}

LocationType PeripheralLocation::get_type() const
{
    return LocationType::Peripheral;
}
