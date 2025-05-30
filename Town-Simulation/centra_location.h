#pragma once
#include "location.h"

class central_location : public location{
public:
    central_location() = default;
    virtual double rent_multiplier() const override;
    virtual location* clone() const override;
};
