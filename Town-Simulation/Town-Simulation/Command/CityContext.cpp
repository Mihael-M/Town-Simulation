#include <stdio.h>
#include "CityContext.h"

City* CityContext::theCity = nullptr;

CityContext* CityContext::get_instance()
{
    static CityContext instance;
    return &instance;
}

void CityContext::set_city(City* city)
{
    if(theCity)
        free_city();
    CityContext::theCity = city;
}

City* CityContext::get_city() const
{
    return theCity;
}

bool CityContext::city_exists() const
{
    return theCity != nullptr;
}

void CityContext::free_city()
{
    delete theCity;
}

CityContext::~CityContext()
{
    free_city();
}
