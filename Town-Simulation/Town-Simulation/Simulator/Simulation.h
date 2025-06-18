#ifndef Simulation_h
#define Simulation_h

#include "City.h"
#include "ResidentManager.h"
#include "Date.h"

class Simulation {
public:
    
    Simulation(ResidentManager* manager);
    
    int simulate_day();
    
    int simulate_days(int n);
    
    void add_to_history(const City& city);
    
    void print_status(std::ostream& os) const;

    unsigned get_current_day() const;
    
    const std::string get_date() const;
    
    void save_simulation_to_file(std::ofstream& ofs) const;

    void load_simulation_from_file(std::ifstream& ifs);
    
    void generate_city(int width, int height);
    
private:
    void back_steps(int n);
    
    bool check_to_remove(std::vector<ResidentEditor>& residents, size_t index) const;
    
    bool check_to_stop()const;
    
    bool are_in_the_same_month() const;
    ResidentManager* manager;
    
    Date date;
    
    Date initial_date;
    
};

#endif /* Simulation_h */
