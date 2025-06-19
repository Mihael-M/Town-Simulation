#ifndef Command_h
#define Command_h

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Utils.h"

class Command{
public:
    virtual void execute(const std::vector<std::string>& args) = 0;
    virtual ~Command() = default;
 
};

#endif /* Command_h */
