#pragma once
#include "Location.h"

class CentralLocation : public Location{
public:
    CentralLocation() = default;
    virtual double rent_multiplier() const override;
    virtual Location* clone() const override;
};
