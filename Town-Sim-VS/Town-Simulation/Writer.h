#ifndef Writer_h
#define Writer_h

#include <string>
#include "Simulation.h"

class Writer{
public:
    Writer(const std::string& fileName);
    
    virtual void write(Simulation* sim) const = 0;

    virtual ~Writer() = default;
protected:
    std::string fileName;
};

#endif /* Writer_h */
