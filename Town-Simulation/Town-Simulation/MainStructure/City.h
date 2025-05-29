#ifndef City_h
#define City_h
#include <vector>
#include "Building.h"


class City{
public:
    
    //constructors:
    
    City(int width,int height);
    
    
    //functionality:
    
    void add_building(int x, int y,Building* building);
    
    
    // TODO:: and make functionality for saving in files...
    
    void simulate_day();
    
    void simulate_month();
    
    void print_status();
    
    Building* get_building_at(int x, int y);
    
    int get_width() const;
    
    int get_height() const;
    
    //memory management:
    
    ~City();
    
    
private:
    // maybe big four...?
    
    void freeDynamic();
    bool is_central(int x, int y) const;
    bool is_peripheral(int x, int y) const;
    
    std::vector<std::vector<Building*>> grid;
    int width;
    int height;
    int currentDay;
    
};




#endif /* City_h */
