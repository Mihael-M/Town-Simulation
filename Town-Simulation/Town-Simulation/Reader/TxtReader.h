#ifndef TxtReader_h
#define TxtReader_h

#include "Reader.h"

class TxtReader : public Reader{
public:
    TxtReader(const std::string& fileName);
    
    virtual void read() override;
};
#endif /* TxtReader_h */
