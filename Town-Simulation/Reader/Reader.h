#ifndef Reader_h
#define Reader_h

#include <string>
#include "Simulation.h"

class Reader{
public:
    Reader(const std::string& fileName);
    
    virtual void read(Simulation* sim) = 0;
    
    virtual ~Reader() = default;
    
protected:
    std::string fileName;
};

#endif /* Reader_h */
