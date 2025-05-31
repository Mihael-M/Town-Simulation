#pragma once
#include "Constants.hpp"

class Location{
public:
    virtual ~Location() = default;
    virtual double rent_multiplier() const = 0;
    virtual Location* clone() const = 0;
};
