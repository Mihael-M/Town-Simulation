#ifndef Simulation_h
#define Simulation_h

#include "City.h"
#include "ResidentManager.h"

class Simulation {
public:
    
    Simulation(int currentDay, ResidentManager* manager);
    
    int simulate_day();
    
    int simulate_days(int n);
    
    void add_to_history(const City& city);
    
    void print_status(std::ostream& os) const;

    int get_current_day() const;
    
    void save_simulation_to_file(std::ofstream& ofs) const;

private:
    bool is_new_month();
    
    void update_day();
    
    
    
    ResidentManager* manager;
    
    std::vector<City> history;
    
    int currentDay;
    
};

#endif /* Simulation_h */
