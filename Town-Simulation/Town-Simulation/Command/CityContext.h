#ifndef CityContext_h
#define CityContext_h
#include <iostream>
#include "City.h"


class CityContext{
public:
    static CityContext* get_instance();
    
    void set_city(City* city);
    
    City* get_city() const;
    
    bool city_exists() const;
    
private:
    CityContext() = default;
    static City* theCity;
};

#endif /* CityContext_h */
