#ifndef LocationFactory_h
#define LocationFactory_h
#include "CentralLocation.h"
#include "PeripheralLocation.h"
#include "LocationType.h"

class LocationFactory{
  
public:
    
    LocationFactory(int width,int height);
    
    Location* create_location(int x, int y);
    
private:
    bool is_central(int x, int y) const;
    
    bool is_peripheral(int x, int y) const;
    
    LocationType get_location_type(int x, int y) const;
    
private:
    int width;
    
};

#endif /* LocationFactory_h */
