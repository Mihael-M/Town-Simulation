#ifndef ResidentManager_h
#define ResidentManager_h

#include <string>
#include "ResidentEditor.h"

class Resident;
class Building;
class City;


class ResidentManager {
public:
    
    void add_resident(Building* building, Resident* resident);

    void remove_resident(City* city, const std::string& name, unsigned currentDay, size_t index);
    
    void remove_resident(Building* building, const std::string& name, unsigned currentDay);

    void generate_random_residents(City* city, unsigned currentDay);

    std::vector<ResidentEditor>& get_residents();
    
    void bring_back(City* city, size_t index);
    
    void remove_resident(size_t index,City* city, const std::string& name);
    
    void save_residents_to_file(std::ofstream& ofs) const;
    
    void load_residents_from_file(City* city, std::ifstream& ifs);
    
    void print_resident(const Coordinates& coords, const std::string& name);
    
    void forward(bool isFirstDayOfMonth, int currentDay, City* city, size_t index);
    
    size_t size() const;
    
private:
    
    void remove(unsigned currentDay, const std::string& name);
    
    std::vector<ResidentEditor> residents;
};

#endif /* ResidentManager_h */
