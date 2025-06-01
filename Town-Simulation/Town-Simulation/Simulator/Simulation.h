#ifndef Simulation_h
#define Simulation_h

#include "City.h"

class Simulation {
public:
    
    Simulation(City* city);
    
    void simulate_day();
    
    void simulate_month();
    
    void print_status() const;

    int get_current_day() const;

private:
    
    City* city;
    
    int currentDay;
    
};

#endif /* Simulation_h */
