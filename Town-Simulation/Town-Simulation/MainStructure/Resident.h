#ifndef Resident_h
#define Resident_h

#include "Profession.h"
#include <vector>

struct ResidentSnapshot
{
    int day;
    int happiness;
    double money;
    int lifePoints;
};


class Resident{
public:
    //constructors:

    Resident(const std::string& name, Profession* job, int happiness, int money, int lifePoints);
    
    //functionality:
    void set_happiness(int happiness);
    
    void set_life_points(int lifePoints);
    
    void receive_salary();
    
    void print_info() const;
    
    const std::string& get_name() const;
    
    void live_day(bool isFirstDayOfMonth, double rent, int currentDay);
    
    void record_snapshot(int currentDay);
    
    int get_happiness() const;
    
    int get_money() const;
    
    int get_life_points() const;
    
    //memory management:

    ~Resident();
    
private:
    void freeDynamic();
    
    void pay_rent(double amount);
    
    std::string name;
    
    Profession* profession;
    
    int happiness;
    
    double money;
    
    int lifePoints;
    
    std::vector<ResidentSnapshot> history;
};


#endif /* Resident_h */
