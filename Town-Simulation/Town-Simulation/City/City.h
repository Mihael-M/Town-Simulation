#ifndef City_h
#define City_h
#include <vector>
#include "Building.h"


class City{
public:
        
    City(int width,int height);
    
    City(const City& other);
    
    City& operator=(const City& other);
    
    void add_building(int x, int y,Building* building);
    
    Building* get_building_at(int x, int y);
    
    int get_width() const;
    
    int get_height() const;
        
    ~City();
    
    
private:
    void copy_dynamic(const City& other);
    
    void free_dynamic();
   
    void generate_random_buildings();
        
    Location* generate_random_location(int x, int y) const;
    
    std::vector<std::vector<Building*>> grid;
    int width;
    int height;
    
};

#endif /* City_h */
