#include "centra_location.h"

//
//  central_location.cpp
//  Town-Simulation
//
//  Created by Partenov, Hristo on 30.05.25.
//

double central_location::rent_multiplier() const{
    return Constants::CENTRAL_LOCATION_RENT_MULTIPLIER;
}

location* central_location::clone() const{
    return new central_location(*this);
}
