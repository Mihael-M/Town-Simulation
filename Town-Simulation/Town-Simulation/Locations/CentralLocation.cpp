#include "CentralLocation.h"

double CentralLocation::rent_multiplier() const{
    return Constants::CENTRAL_LOCATION_RENT_MULTIPLIER;
}

Location* CentralLocation::clone() const{
    return new CentralLocation(*this);
}

LocationType CentralLocation::get_type() const
{
    return LocationType::Central;
}
