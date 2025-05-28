#ifndef City_h
#define City_h
#include <vector>
#include "Building.h"
class City{
public:
    
    //constructors:
    
    City(int width,int height);
    
    
    //functionality:
    
    void add_building(int x, int y,const Building* building);
    
    void simulate_day();
    
    void simulate_month();
    
    void print_status();
    
    //memory management:
    
    ~City();
    
    
private:
    
    void freeDynamic();
    bool is_central(int x, int y) const;
    bool is_peripheral(int x, int y) const;
    
    std::vector<std::vector<Building*>> grid;
    int width;
    int height;
    int currentDay;
    
};




#endif /* City_h */
