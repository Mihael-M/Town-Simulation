#ifndef Coordinates_h
#define Coordinates_h

class Coordinates{
public:
    Coordinates() = default;
    Coordinates(unsigned x,unsigned y);
    unsigned get_x() const;
    unsigned get_y() const;
private:
    unsigned x = 0;
    unsigned y = 0;
    
};

bool operator==(const Coordinates& lhs, const Coordinates& rhs);
bool operator!=(const Coordinates& lhs, const Coordinates& rhs);


#endif /* Coordinates_h */
