#ifndef City_h
#define City_h
#include <vector>
#include "Building.h"


class City{
public:
        
    City(int width,int height);
    
    
    void add_building(int x, int y,Building* building);
    
    //in command not city!!!!
    
    void simulate_day();
    
    void simulate_month();
    
    void print_status();
    
    Building* get_building_at(int x, int y);
    
    int get_width() const;
    
    int get_height() const;
        
    ~City();
    
    
private:
    
    void freeDynamic();
   
    
    std::vector<std::vector<Building*>> grid;
    int width;
    int height;
    int currentDay;
    
};




#endif /* City_h */
