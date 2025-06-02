#ifndef Resident_h
#define Resident_h
#include "Profession.h"
#include "Building.h"
#include <vector>
#include <cstdlib>

class Profession;
class Building;

class ResidentHistory {
public:
    
    const std::vector<Resident>& get_history() const;
    
    void record_snapshot(const Resident& res);
    
    size_t get_size() const;
    
private:
    std::vector<Resident> history;
    int x;
    int y;
};





struct resident_info{
private:
    int happiness;
    double money;
    int life_points;
    
    static double generate_random_info();

    
public:
    resident_info(int happiness = generate_random_info(), double money = generate_random_info(), int life_points = generate_random_info());
    
    void set_happiness(int happiness);
    
    void set_life_points(int life_points);

    void set_money(double money);

    int get_happiness() const;

    double get_money() const;

    int get_life_points() const;
    
};


class Resident{
public:
    Resident(Building* building, const std::string& name = generate_random_name(), const resident_info& info = *generate_random_resident_info() ,Profession* job = generate_random_profession());
        
    Resident(const Resident& other);
    
    Resident& operator=(const Resident& other);
    
    void receive_salary();
    
    void print_info(std::ostream& os) const;
    
    void print_history(std::ostream& os) const;
    
    const std::string& get_name() const;
    
    void live_day(bool isFirstDayOfMonth, int currentDay);
    
    const ResidentHistory& get_history() const;
    
    void set_building(Building* building);
        
    resident_info get_resident_info() const;
    
    ~Resident();
    
private:
    
    void free_dynamic();
    
    void copy_dynamic(const Resident& other);
    
    void pay_rent();
    
    void pay_for_food();
    
    static Profession* generate_random_profession();
    
    static std::string generate_random_name();
    
    static resident_info* generate_random_resident_info();
    
    
    std::string name;
    
    Profession* profession;
    
    Building* building;
    
    resident_info info;
    
    ResidentHistory history;
};


#endif /* Resident_h */
