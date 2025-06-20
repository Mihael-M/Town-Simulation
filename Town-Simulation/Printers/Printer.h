#pragma once
#include <iostream>

class Printer{
public:
    virtual ~Printer() = default;
    
    virtual void print(const std::string& str = "") const;
    
    virtual void println(const std::string& str = "") const;
};
