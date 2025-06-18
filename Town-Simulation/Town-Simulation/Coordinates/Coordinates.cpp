#include <stdio.h>
#include "Coordinates.h"

Coordinates::Coordinates(unsigned x,unsigned y) : x(x), y(y) {}

unsigned Coordinates::get_x() const
{
    return x;
}
unsigned Coordinates::get_y() const
{
    return y;
}

bool operator==(const Coordinates& lhs, const Coordinates& rhs)
{
    return lhs.get_x() == rhs.get_x() && lhs.get_y() == rhs.get_y();
}
bool operator!=(const Coordinates& lhs, const Coordinates& rhs)
{
    return !(lhs == rhs);
}
