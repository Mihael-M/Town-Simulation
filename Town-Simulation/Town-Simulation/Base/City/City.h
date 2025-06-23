#ifndef City_h
#define City_h
#include <vector>
#include "BuildingFactory.h"
#include "Coordinates.h"

class City{
public:
        
    City(int width,int height);
    
    City(int width, int height, std::vector<std::vector<Building*>>& grind);
    
    City(const City& other);
    
    City& operator=(const City& other);
    
    City(std::ifstream& ifs);
    
    void add_building(const Coordinates& coordinates,Building* building);
    
    Building* get_building_at(const Coordinates& coordinates);
    
    void save_city_to_file(std::ofstream& ofs) const;
    
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
