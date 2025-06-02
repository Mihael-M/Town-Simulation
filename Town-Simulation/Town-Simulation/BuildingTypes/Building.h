#ifndef Building_h
#define Building_h
#include "Resident.h"
#include "Constants.hpp"
#include "BuildingType.h"
#include "Location.h"
#include <string>
#include <vector>

class Resident;

class Building{
public:
    Building(BuildingType type, Location* loc, size_t capacity = generate_number_residents());
    
    Building(const Building& other);
    
    Building& operator=(const Building& other);
        
    std::vector<Resident*> get_residents() const;

    void add_resident(Resident* resident);
    
    void remove_resident(const std::string& name);
    
    virtual double calculate_rent() const = 0;
    
    virtual double get_base_rent() const = 0;
    
    virtual Building* clone() const = 0;
    
    void print_residents(std::ostream& os) const;
    
    void print_building(std::ostream& os) const;
    
    void print_resident(const std::string& name) const;
    
    
    size_t get_size() const;
    size_t get_capacity() const;
    bool is_empty() const;
    bool is_full() const;
    
    virtual ~Building();
    
protected:
    
    std::vector<Resident*> residents;
    
    
    BuildingType type;
    Location* loc;
    
private:
    void copy_dynamic(const Building& other);
    
    static size_t generate_number_residents();
    
    void generate_random_residents();
    
    void free_dynamic();
};


#endif /* Building_h */
