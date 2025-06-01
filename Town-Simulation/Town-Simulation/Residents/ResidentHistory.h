#ifndef ResidentHistory_h
#define ResidentHistory_h
#include "Resident.h"


class ResidentHistory {
public:
    
    const std::vector<Resident>& get_history() const;
    
    void record_snapshot(const Resident& res);
    
    size_t get_size() const;
    
private:
    std::vector<Resident> history;
    int x;
    int y;
};

#endif /* ResidentHistory_h */
