#include <stdio.h>
#include "Resident.h"
#include "Building.h"
#include <iostream>
#include <stdexcept>
#include "ProfessionFactory.h"

resident_info::resident_info(std::ifstream& ifs)
{
    load_info_from_file(ifs);
}

void resident_info::load_info_from_file(std::ifstream& is)
{
    int happiness, lifePoints;
    double money;
    unsigned born;
    int removed;
    std::string causeStr;
    RemovalCause cause;
    
    if (!(is >> happiness)) throw std::runtime_error("Failed to read happiness");
    if (!(is >> money)) throw std::runtime_error("Failed to read money");
    if (!(is >> lifePoints)) throw std::runtime_error("Failed to read life points");
    if (!(is >> born)) throw std::runtime_error("Failed to read when resident was born");
    if (!(is >> removed)) throw std::runtime_error("Failed to read when resident was removed");
    if (!(is >> causeStr)) throw std::runtime_error("Failed to read the couse for removal");
    
    if(causeStr == "None")
        cause = RemovalCause::None;
    else if(causeStr == "Died")
        cause = RemovalCause::Died;
    else cause = RemovalCause::RemovedManually;
    
    set_happiness(happiness);
    set_money(money);
    set_life_points(lifePoints);
    set_born(born);
    set_removal_day(removed);
    set_cause(cause);
}

Resident::Resident(std::ifstream& is){
    load_resident_from_file(is);
}

void Resident::load_resident_from_file(std::ifstream& is)
{
    std::string name, professionType;
    is>>name;
    this->name = name;
    is >> professionType;
    ProfessionFactory* factory = ProfessionFactory::get_factory();
    profession = factory->create_profession(professionType);
    if (!profession) throw std::runtime_error("Invalid profession type");
    
    info = new resident_info(is);
}

Resident::ResidentMemento::ResidentMemento(std::ifstream& is)
{
    load_memento_from_file(is);
}

void Resident::ResidentMemento::load_memento_from_file(std::ifstream& is)
{
    std::string name, professionType;
    is>>name;
    this->name = name;
    if(name == "") throw std::runtime_error("Invalid resident name");
    is>>professionType;
    
    ProfessionFactory* factory = ProfessionFactory::get_factory();
    profession = factory->create_profession(professionType);
    if (!profession) throw std::runtime_error("Invalid profession type");
    
    info = new resident_info(is);
}

Resident::ResidentMemento* Resident::load_memento_from_file(std::ifstream& ifs)
{
    return new ResidentMemento(ifs);
}

void Resident::free_dynamic(){
    delete profession;
    delete info;
    profession = nullptr;
    info = nullptr;
}

Resident::~Resident(){
    free_dynamic();
}


Resident::Resident(resident_info* info, const std::string& name, Profession* job) : info(info) , name(name), profession(job) {}

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
    int curr_balance = info->get_money();
    int rent = building->calculate_rent();
    
    info->set_money(curr_balance -= rent);
    
    if (curr_balance < 0)
        info->set_money(0);
}


const std::string& Resident::get_name() const {
    return name;
}

void Resident::pay_for_food(){
    int curr_balance = info->get_money();
    
    info->set_money(curr_balance -= Constants::FOOD_EXPENSES);
    if(curr_balance < 0)
        info->set_money(0);
}


void Resident::receive_salary() {
    info->set_money(info->get_money() + profession->get_salary());
    profession->monthly_update(*this);
}

resident_info* Resident::get_resident_info() const{
    return info;
}

void Resident::live_day(bool isFirstDayOfMonth, int currentDay, Building* building) {
    if (isFirstDayOfMonth)
    {
        pay_rent(building);
        receive_salary();
    }
        
    pay_for_food();
}

void Resident::print_info(std::ostream& os) const
{
    os<< "                "<< "Profession: " << profession->get_type() << std::endl;
    os << "                "<< "Happiness: " << info->get_happiness() << std::endl;
    os<< "                "<< "Money: " << info->get_money() << std::endl;
    os<< "                "<< "Life: " << info->get_life_points() << std::endl;
}

void Resident::save_to_file(std::ofstream& ofs) const
{
    ofs<< info->get_coordinates().get_x() << " "<< info->get_coordinates().get_y()<<std::endl;
    ofs<<name<<std::endl;
    ofs<<profession->get_type()<<std::endl;
    info->save_info_to_file(ofs);
}

void resident_info::save_info_to_file(std::ofstream& ofs) const
{
    ofs<< happiness << std::endl;
    ofs<< money << std::endl;
    ofs<< life_points << std::endl;
    ofs<<born <<std::endl;
    ofs<<removalDay<<std::endl;
    save_removal_Cause(ofs);
}



void resident_info::save_removal_Cause(std::ofstream& ofs) const
{
    switch (removalCause) {
        case RemovalCause::None:
            ofs<< "None" << std::endl;
            break;
        case RemovalCause::Died:
            ofs<< "Died" << std::endl;
            break;
        case RemovalCause::RemovedManually:
            ofs<< "RemovedManually" << std::endl;
            break;
        default:
            ofs<< "None" << std::endl;
            break;
    }
}

Profession* Resident::generate_random_profession()
{
    ProfessionFactory* factory = ProfessionFactory::get_factory();
    
    int type = std::rand() % Constants::professionNames.size();
    
    return factory->create_profession(Constants::professionNames[type]);
}

std::string Resident::generate_random_name()
{
    int index = std::rand() % Constants::names.size();
    return Constants::names[index];
}

resident_info* Resident::generate_random_resident_info()
{
    return new resident_info();
}



Profession* Resident::get_profession() const
{
    return profession;
}

resident_info::resident_info(const Coordinates& coordinates, unsigned born, int happiness, double money, int life_points) : born(born), coordinates(coordinates){
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

void resident_info::set_born(unsigned day)
{
    born = day;
}

unsigned resident_info::get_born() const
{
    return born;
}

bool resident_info::is_alive() const
{
    return removalDay == -1;
}

const Coordinates& resident_info::get_coordinates() const
{
    return coordinates;
}

void resident_info::set_removal_day(int day)
{
    removalDay = day;
}

int resident_info::get_removal_day() const
{
    return removalDay;
}

void resident_info::set_cause(const RemovalCause& cause)
{
    removalCause = cause;
}

RemovalCause resident_info::get_cause() const
{
    return removalCause;
}

void Resident::set_name(const std::string& name){
    this->name = name;
}

void Resident::set_profession(Profession* profession){
    this->profession = profession;
}

void Resident::set_resident_info(resident_info* info){
    this->info = info;
}



Resident::ResidentMemento::ResidentMemento(const std::string& name, Profession* profession, resident_info* info){
    this->name = name;
    this->profession = profession;
    this->info = info;
}

const std::string& Resident::ResidentMemento::get_name() const{
    return name;
}

Profession* Resident::ResidentMemento::get_profession() const{
    return profession;
}

resident_info* Resident::ResidentMemento::get_info() const{
    return info;
}

Resident::ResidentMemento* Resident::take_snapshot(){
    return new ResidentMemento(name, profession->clone(),new resident_info(*info));
}

void Resident::restore(ResidentMemento* memento){
name = memento->get_name();
profession = memento->get_profession();
info = memento->get_info();
}
