#include <stdio.h>
#include "Resident.h"
#include <iostream>
#include <stdexcept>
#include "ProfessionFactory.h"

ResidentSnapshot::ResidentSnapshot(const Resident& res) : name(res.get_name()), profession(res.get_profession()), info(res.get_resident_info()) {}

void ResidentSnapshot::save_snapshot_to_file(std::ofstream& ofs) const
{
    ofs<<name<<std::endl;
    ofs<<profession->get_type()<<std::endl;
    info.save_info_to_file(ofs);
}

void ResidentSnapshot::print_history(std::ostream& os) const
{
    os<< "Profession: " << profession->get_type() << std::endl;
    os << "Happiness: " << info.get_happiness() << std::endl;
    os<<"Money: " << info.get_money() << std::endl;
    os<<"Life: " << info.get_life_points() << std::endl;
}


void ResidentHistory::record_snapshot(const Resident& res)
{
    history.push_back(ResidentSnapshot(res));
}

const std::vector<ResidentSnapshot>& ResidentHistory::get_history() const
{
    return history;
}

size_t ResidentHistory::get_size() const
{
    return history.size();
}

void ResidentHistory::save_history_to_file(std::ofstream& ofs) const
{
    for(int i = 0; i < history.size(); i++)
    {
        history[i].save_snapshot_to_file(ofs);
    }
}




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
}


Resident::Resident(const std::string& name, const resident_info& info, Profession* job) : info(info) , name(name), profession(job) {}

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
    profession = other.profession->clone();
}



void Resident::pay_rent(Building* building){
    int curr_balance = info.get_money();
    int rent = building->calculate_rent();
    
    info.set_money(curr_balance -= rent);
    
    if (curr_balance < 0)
        info.set_money(0);
}


const std::string& Resident::get_name() const {
    return name;
}

void Resident::pay_for_food(){
    int curr_balance = info.get_money();
    
    info.set_money(curr_balance -= Constants::FOOD_EXPENSES);
    if(curr_balance < 0)
        info.set_money(0);
}


void Resident::receive_salary() {
    info.set_money(info.get_money() + profession->get_salary());
    profession->monthly_update(*this);
}

resident_info Resident::get_resident_info() const{
    return info;
}


void Resident::live_day(bool isFirstDayOfMonth, int currentDay, Building* building) {
    history.record_snapshot(*this);
    if (isFirstDayOfMonth)
    {
        pay_rent(building);
        receive_salary();
    }
        
    pay_for_food();
    
}

void Resident::print_info(std::ostream& os) const
{
    os<< "Profession: " << profession->get_type() << std::endl;
    os << "Happiness: " << info.get_happiness() << std::endl;
    os<<"Money: " << info.get_money() << std::endl;
    os<<"Life: " << info.get_life_points() << std::endl;
}

void Resident::save_to_file(std::ofstream& ofs) const
{
    ofs<<name;
    ofs<<profession->get_type();
    info.save_info_to_file(ofs);
    history.save_history_to_file(ofs);
}

void resident_info::save_info_to_file(std::ofstream& ofs) const
{
    ofs<< happiness << std::endl;
    ofs<< money << std::endl;
    ofs<< life_points << std::endl;
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
        history.get_history()[i].print_history(os);
    }
}




Profession* Resident::get_profession() const
{
    return profession;
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

