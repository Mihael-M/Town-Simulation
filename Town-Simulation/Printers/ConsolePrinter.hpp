#pragma once
#include "Printer.h"

class ConsolePrinter : public Printer{
public:
    ConsolePrinter() = default;
    
    virtual void print(const std::string& str) const override;
    
    virtual void println(const std::string& str) const override;
};

void ConsolePrinter::print(const std::string& str) const{
    std::cout<<str;
}

void ConsolePrinter::println(const std::string& str) const{
    std::cout<<str<<std::endl;
}
