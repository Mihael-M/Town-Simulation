#include <stdio.h>
#include "Resident.h"
#include <iostream>
#include <stdexcept>
#include "ProfessionFactory.h"

static std::vector<std::string> professionNames = {
    "Teacher", "Programmer", "Miner", "Unemployed"
};

static std::vector<std::string> names = {
    "Bobby", "Kevin", "Olq", "Petq", "Kosta", "Trump", "Viktor", "Elena"
};

void Resident::free_dynamic(){
    delete profession;
}

Resident::~Resident(){
    free_dynamic();
    profession = nullptr;
    building = nullptr;
}

void Resident::set_building(Building* building)
{
    this->building = building;
}


Resident::Resident(Building* building, const std::string& name, const resident_info& info, Profession* job) : info(info) , name(name), profession(job), building(building) {}

const ResidentHistory& Resident::get_history() const
{
    return history;
}


Resident::Resident(const Resident& other) : name(other.name), info(other.info)
{
    copy_dynamic(other);
}

Resident& Resident::operator=(const Resident& other)
{
    if(this != & other)
    {
        name = other.name;
        info = other.info;
        free_dynamic();
        copy_dynamic(other);
    }
    return *this;
}

void Resident::copy_dynamic(const Resident& other)
{
    building = other.building ? other.building->clone() : nullptr;
    profession = other.profession->clone();
}



void Resident::pay_rent(){
    int curr_balance = info.get_money();
    int rent = building->calculate_rent();
    
    curr_balance -= rent;
    
    if (curr_balance < 0)
        curr_balance = 0;
}


const std::string& Resident::get_name() const {
    return name;
}

void Resident::pay_for_food(){
    int curr_balance = info.get_money();
    
    curr_balance -= Constants::FOOD_EXPENSES;
    if(curr_balance < 0)
        curr_balance = 0;
}


void Resident::receive_salary() {
    info.set_money(info.get_money() + profession->get_salary());
    profession->monthly_update(this);
}

resident_info Resident::get_resident_info() const{
    return info;
}





void Resident::live_day(bool isFirstDayOfMonth, int currentDay) {
    if (isFirstDayOfMonth)
    {
        pay_rent();
        receive_salary();
    }
        
    pay_for_food();
    history.record_snapshot(*this);
}

void Resident::print_info(std::ostream& os) const
{
    os<< "Profession: " << profession->get_type() << "\n";
    os << "Happiness: " << info.get_happiness() << std::endl;
    os<<"Money: " << info.get_money() << std::endl;
    os<<"Life: " << info.get_life_points() << std::endl;
}


Profession* Resident::generate_random_profession()
{
    ProfessionFactory* factory = ProfessionFactory::get_factory();
    
    int type = std::rand() % professionNames.size();
    
    return factory->create_profession(professionNames[type]);
}

std::string Resident::generate_random_name()
{
    int index = std::rand() % names.size();
    return names[index];
}

resident_info* Resident::generate_random_resident_info()
{
    return new resident_info();
}

void Resident::print_history(std::ostream& os) const
{
    for(int i = 0; i < history.get_size(); i++)
    {
        std::cout<< i << ": ";
        history.get_history()[i].print_info(os);
    }
}


void ResidentHistory::record_snapshot(const Resident& res)
{
    history.push_back(res);
}

const std::vector<Resident>& ResidentHistory::get_history() const
{
    return history;
}

size_t ResidentHistory::get_size() const
{
    return history.size();
}


resident_info::resident_info(int happiness, double money, int life_points){
    set_happiness(happiness);
    set_money(money);
    set_life_points(life_points);
}

void resident_info::set_happiness(int happiness){
    if(happiness < 0)
        throw std::invalid_argument("Invalid happiness!");
    this->happiness = happiness;
}

void resident_info::set_life_points(int life_points){
    if(life_points < 0)
        throw std::invalid_argument("Invalid life points!");
    this->life_points = life_points;
}

void resident_info::set_money(double money){
    this->money = money;
}

int resident_info::get_happiness() const {
    return happiness;
}

double resident_info::get_money() const {
    return money;
}

int resident_info::get_life_points() const {
    return life_points;
}

double resident_info::generate_random_info()
{
    return Constants::RESIDENT_MIN_INFO + (std::rand() % (Constants::RESIDENT_MAX_INFO - Constants::RESIDENT_MIN_INFO + 1));
}
