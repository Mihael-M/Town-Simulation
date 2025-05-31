#ifndef ProfessionFactory_h
#define ProfessionFactory_h
#include "Constants.hpp"
#include "ProgrammerCreator.h"
#include "UnemployedCreator.h"
#include "MinerCreator.h"
#include "TeacherCreator.h"

class ProfessionFactory {
public:
    
    static ProfessionFactory* get_factory();
    
    void register_profession(const ProfessionCreator* creator);
    
    Profession* create_profession(std::string& type);
    
private:
    
    const ProfessionCreator* get_creator(std::string& type) const;
    
    
private:
    ProfessionFactory() : count(0) {}
    
    ~ProfessionFactory() = default;
    
    ProfessionFactory(const ProfessionFactory& other) = delete;
    
    ProfessionFactory& operator=(const ProfessionFactory& other) = delete;
    
private:
    static ProfessionFactory* theProfessionFactory;
    const ProfessionCreator* creators[Constants::MAX_NUMBER_TYPES];
    int count;
    
};


#endif /* ProfessionFactory_h */
