#ifndef ResidentEditor_h
#define ResidentEditor_h
#include "Resident.h"

class ResidentEditor{
public:
    ResidentEditor(Resident* resident);
    
    ResidentEditor(const ResidentEditor& other);
    
    ResidentEditor& operator=(const ResidentEditor& other);
    
    ResidentEditor(std::ifstream& ifs);
    
    void print_history(std::ostream& os) const;

    void save_memento_to_file(std::ofstream& ofs) const;
    
    
    
    Resident* get_resident() const;
    
    void go_forward(bool isFirstDayOfMonth, int currentDay, Building* building);
    
    void go_back();
    
    ~ResidentEditor();
    
private:

    void load_memento_from_file(std::ifstream& ifs);
    
    void free_dynamic();
    
    void copy_dynamic(const ResidentEditor& other);
    
    void print_memento(std::ostream& os, size_t index) const;
    
    void save_memento_to_file(std::ofstream& ofs, size_t index) const;
    
    std::vector<Resident::ResidentMemento*> stateHistory;
    
    Resident* resident;
};
#endif /* ResidentEditor_h */
