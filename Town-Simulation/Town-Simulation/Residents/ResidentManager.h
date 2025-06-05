#ifndef ResidentManager_h
#define ResidentManager_h

#include <string>

class Resident;
class Building;
class City;


class ResidentManager {
public:
    
    void addResident(City* city, int x, int y, Resident* resident);

    void removeResident(City* city, int x, int y, const std::string& name);
};

#endif /* ResidentManager_h */
