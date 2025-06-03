#include <stdio.h>
#include "Simulation.h"
#include "CityContext.h"
#include <iostream>


Simulation::Simulation(int currentDay, ResidentManager* manager) : manager(manager), currentDay(currentDay) {}

int Simulation::simulate_day() {
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!city)
        throw std::runtime_error("City not created!");
    int res = 0;
    currentDay++;
    if(is_new_month())
        update_day();
    for (int i = 0; i < city->get_height(); i++) {
        for (int j = 0; j < city->get_width(); j++) {
            Building* building = city->get_building_at(i, j);
            
            std::vector<Resident*> residents = building->get_residents();
            for(int z = 0; z < residents.size(); z++)
            {
                if(residents[z]->get_resident_info().get_money() <= 0 && residents[z]->get_resident_info().get_happiness() <= 0 && residents[z]->get_resident_info().get_life_points() <= 0)
                {
                    manager->removeResident(city, i, j, residents[z]->get_name());
                    res++;
                }
                residents[z]->live_day(currentDay == 1, currentDay, building);
            }
            
        }
    }
    add_to_history(*city);
    return res;
}

void Simulation::add_to_history(const City& city)
{
    history.push_back(city);
}


int Simulation::simulate_days(int n)
{
    int peopleRemoved = 0;
    if(n > 0){
        while(n != 0){
            peopleRemoved += simulate_day();
            n--;
        }
        return peopleRemoved;
    }
    else {
        for (int i = 0; i < -n && history.size() > 1; ++i) {
            history.pop_back();
            currentDay--;
        }

        CityContext* context = CityContext::get_instance();
        City* city = context->get_city();
        *city = history.back();
        return peopleRemoved;
    }
}

void Simulation::print_status(std::ostream& os) const {
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!city)
        throw std::runtime_error("City not created!");
    
    for (int i = 0; i < city->get_height(); i++) {
        for (int j = 0; j < city->get_width(); j++) {
            Building* building = city->get_building_at(i, j);
            os<<"Location " << i << " " << j << ": ";
            building->print_building(os);
            building->print_residents(os);
        }
    }
}

bool Simulation::is_new_month()
{
    return currentDay == 30;
}

void Simulation::update_day()
{
    currentDay = 1;
}

void Simulation::save_simulation_to_file(std::ofstream& ofs) const
{
    ofs<<history.size()<<std::endl;
    for(int i = 0; i < history.size(); i++)
        history[i].save_city_to_file(ofs);
}

void Simulation::load_simulation_from_file(std::ifstream& ifs){
    if (!history.empty()) {
        history.clear();
    }
    std::string line;
    CityContext* context = CityContext::get_instance();
    int size;
    ifs>>size;
    
    for(int i = 0; i < size; i++){
            City* city = new City(ifs);
            context->set_city(city);
            history.push_back(*city);
    }
}
