#ifndef Resident_h
#define Resident_h
#include "Profession.h"
#include "Building.h"
#include <vector>
#include <cstdlib>



class Profession;
class Building;

struct resident_info{
private:
    int happiness;
    double money;
    int life_points;
    
    static double generate_random_info()
    {
        return Constants::RESIDENT_MIN_INFO + (std::rand() % (Constants::RESIDENT_MAX_INFO - Constants::RESIDENT_MIN_INFO + 1));
    }

    
public:
    resident_info(int happiness = generate_random_info(), double money = generate_random_info(), int life_points = generate_random_info()){
        set_happiness(happiness);
        set_money(money);
        set_life_points(life_points);
    }
    
    void set_happiness(int happiness){
        if(happiness < 0)
            throw std::invalid_argument("Invalid happiness!");
        this->happiness = happiness;
    }
    
    void set_life_points(int life_points){
        if(life_points < 0)
            throw std::invalid_argument("Invalid life points!");
        this->life_points = life_points;
    }

    void set_money(double money){
        this->money = money;
    }

    int get_happiness() const {
        return happiness;
    }

    double get_money() const {
        return money;
    }

    int get_life_points() const {
        return life_points;
    }
    
};

struct resident_snapshot{
    int day;
    resident_info info;
};


class Resident{
public:
    Resident(Building* building,const std::string& name = generate_random_name(), const resident_info& info = *generate_random_resident_info() ,Profession* job = generate_random_profession());
        
    void receive_salary();
    
    void print_info() const;
    
    const std::string& get_name() const;
    
    void live_day(bool isFirstDayOfMonth, int currentDay);
    
    void record_snapshot(int currentDay);
    
    void set_building(Building* building);
        
    resident_info get_resident_info() const;
    
    ~Resident();
    
private:
    void free_dynamic();
    
    void pay_rent();
    
    void pay_for_food();
    
    static Profession* generate_random_profession();
    
    static std::string generate_random_name();
    
    static resident_info* generate_random_resident_info();
    
    
    std::string name;
    
    Profession* profession;
    
    Building* building;
    
    resident_info info;
    
    std::vector<resident_snapshot> history;
};


#endif /* Resident_h */
