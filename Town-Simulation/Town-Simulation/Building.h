#ifndef Building_h
#define Building_h
#include "Resident.h"
#include <string>

class Building{
public:
    Building(std::string& type, int capacity, double rent);
    
    
    void add_resident(Resident* resident);
    
    double calculate_rent() const;
    
    
    virtual ~Building();
    
protected:
    
    
    std::vector<Resident*> residents;
    int capacity;
    std::string type;
    double rent;
    bool isCentral;
    bool isPeripheral;
};


#endif /* Building_h */
