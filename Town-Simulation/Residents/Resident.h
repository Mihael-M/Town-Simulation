#ifndef Resident_h
#define Resident_h
#include <vector>
#include <cstdlib>
#include <fstream>

#include "Coordinates.h"
#include "ProfessionFactory.h"

class Building;

enum class RemovalCause {
    None,
    Died,
    RemovedManually
};

struct resident_info{
private:
    
   
    
    int happiness;
    double money;
    int life_points;
    
    unsigned born;
    
    int removalDay = -1;
    
    Coordinates coordinates;
    
    RemovalCause removalCause = RemovalCause::None;
    
    static double generate_random_info();
    
    void save_removal_Cause(std::ofstream& ofs) const;

public:
    resident_info(const Coordinates& coordinates = Coordinates(), unsigned born = 0, int happiness = generate_random_info(), double money = generate_random_info(), int life_points = generate_random_info());
    
    resident_info(std::ifstream& ifs);
    
    void set_removal_day(int day);
    
    int get_removal_day() const;
    
    void set_cause(const RemovalCause& cause);
    
    RemovalCause get_cause() const;
    
    void set_born(unsigned day);
    
    void set_happiness(int happiness);
    
    void set_life_points(int life_points);

    void set_money(double money);
    
    unsigned get_born() const;

    int get_happiness() const;

    double get_money() const;

    int get_life_points() const;
    
    void save_info_to_file(std::ofstream& ofs) const;
    
    void load_info_from_file(std::ifstream& ifs);
    
    bool is_alive() const;
    
    const Coordinates& get_coordinates() const;
    
};


class Resident{
public:
    Resident(resident_info* info = generate_random_resident_info() ,const std::string& name = generate_random_name(), Profession* job = generate_random_profession());
        
    Resident(const Resident& other);
    
    Resident& operator=(const Resident& other);
    
    Resident(std::ifstream& is);
    
    void receive_salary();
    
    void print_info(std::ostream& os) const;
    
    const std::string& get_name() const;
    
    void live_day(bool isFirstDayOfMonth, int currentDay, Building* building);
        
    resident_info* get_resident_info() const;
    
    Profession* get_profession() const;
    
    void set_name(const std::string& name);
    
    void set_profession(Profession* profession);
    
    void set_resident_info(resident_info* info);
    
    void save_to_file(std::ofstream& ofs) const;
    
    ~Resident();
    
private:
    
    void free_dynamic();
    
    void copy_dynamic(const Resident& other);
    
    void pay_rent(Building* building);
    
    void pay_for_food();
    
    static Profession* generate_random_profession();
    
    static std::string generate_random_name();
    
    static resident_info* generate_random_resident_info();
    
    void load_resident_from_file(std::ifstream& ifs);
    
    
    
public:
    class ResidentMemento{
    private:
        friend class Resident;
        std::string name;
        
        Profession* profession;
        
        resident_info* info;
        
        void load_memento_from_file(std::ifstream& ifs);

        ResidentMemento(const std::string& name, Profession* profession, resident_info* info);
        
        ResidentMemento(std::ifstream& ifs);
    public:
        
        const std::string& get_name() const;
        
        Profession* get_profession() const;
        
        resident_info* get_info() const;
        
    };
    
    ResidentMemento* load_memento_from_file(std::ifstream& ifs);
    
    ResidentMemento* take_snapshot();
    
    void restore(ResidentMemento* memento);
    
private:
    std::string name;
    
    Profession* profession;
    
    resident_info* info;
};


#endif /* Resident_h */
