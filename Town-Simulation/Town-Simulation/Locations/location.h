#pragma once
#include "Constants.hpp"

class location{
public:
    virtual ~location() = default;
    virtual double rent_multiplier() const = 0;
    virtual location* clone() const = 0;
};
