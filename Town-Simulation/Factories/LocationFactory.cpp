#include <stdio.h>
#include "LocationFactory.h"
#include <cmath>
#include <stdexcept>

LocationFactory::LocationFactory(int width,int height) : width(width), height(height) {}

Location* LocationFactory::create_location(int x, int y)
{
    switch (get_location_type(x, y)) {
        case LocationType::Central:
            return new CentralLocation();
        case LocationType::Peripheral:
            return new PeripheralLocation();
        default:
            return nullptr;
    }
}

bool LocationFactory::is_central(int x, int y) const
{
    if(x > width || y > height)
        throw std::invalid_argument("Invalid coordinates");
    
    int centerX = width / 2;
    int centerY = height / 2;
    double distance = std::sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
    return distance <= std::fmin(width, height) / 8.0;
}

bool LocationFactory::is_peripheral(int x, int y) const
{
    return !is_central(x, y);
}

LocationType LocationFactory::get_location_type(int x, int y) const
{
   if (is_central(x, y))
       return LocationType::Central;
   if (is_peripheral(x, y))
       return LocationType::Peripheral;
   return LocationType::Unknown;
}
