#ifndef Building_h
#define Building_h
#include "Resident.h"
#include "BuildingType.h"
#include <string>
#include <vector>



class Building{
public:
    //constructors:

    Building(const BuildingType type, int capacity);
    
    //functionality:

    virtual void add_resident(Resident* resident);
    
    virtual void remove_resident(const std::string& name);
    
    virtual double calculate_rent() const = 0;
    
    virtual double get_base_rent() const = 0;
    
    virtual Building* clone() const = 0;
    
    void setLocation(bool central, bool peripheral);

    //memory management:
    
    virtual ~Building();

protected:
    
    
    std::vector<Resident*> residents;
    
    int capacity;
    
    BuildingType type;
    
    bool isCentral;
    
    bool isPeripheral;
    
private:
    void freeDynamic();
};


#endif /* Building_h */
