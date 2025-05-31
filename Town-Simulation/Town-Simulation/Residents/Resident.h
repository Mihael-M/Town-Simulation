#ifndef Resident_h
#define Resident_h
#include "Profession.h"
#include "Building.h"
#include <vector>

class Profession;
class Building;

struct resident_info{
private:
    int happiness;
    double money;
    int life_points;
    
public:
    resident_info(int happiness, double money, int life_points){
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
    Resident(const std::string& name, Profession* job, const resident_info& info, Building* building);
        
    void receive_salary();
    
    void print_info() const;
    
    const std::string& get_name() const;
    
    void live_day(bool isFirstDayOfMonth, int currentDay);
    
    void record_snapshot(int currentDay);
    
    void set_building(Building* building);
    
    resident_info get_resident_info() const;
    
    ~Resident();
    
private:
    void freeDynamic();
    
    void pay_rent();
    void pay_for_food();
    
    std::string name;
    
    Profession* profession;
    
    Building* building;
    
    resident_info info;
    
    std::vector<resident_snapshot> history;
};


#endif /* Resident_h */
