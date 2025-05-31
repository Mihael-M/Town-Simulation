#pragma once
#include "location.h"


class peripheral_location : public location {
public:
    peripheral_location() = default;
    virtual double rent_multiplier() const override;
    virtual location* clone() const override;
};
