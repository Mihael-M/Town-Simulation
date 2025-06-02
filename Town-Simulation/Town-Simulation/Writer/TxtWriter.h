#ifndef TxtWriter_h
#define TxtWriter_h

#include "Writer.h"

class TxtWriter : public Writer{
public:
    TxtWriter(const std::string& fileName);
    
    virtual void write(Simulation* sim) const override;
};

#endif /* TxtWriter_h */
