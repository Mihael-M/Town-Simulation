//
//  Reader.h
//  Town-Simulation
//
//  Created by Mishoni Mihaylov on 2.06.25.
//

#ifndef Reader_h
#define Reader_h

#include <string>

class Reader{
public:
    Reader(const std::string& fileName);
    
    virtual void read() = 0;
    
    virtual ~Reader();
    
protected:
    std::string fileName;
};

#endif /* Reader_h */
