#include <stdio.h>
#include "Simulation.h"
#include "CityContext.h"
#include <iostream>


Simulation::Simulation(ResidentManager* manager) : manager(manager){
    date = Date();
    initial_date = date;
}

bool Simulation::check_to_stop()const
{
    return  date.get_day() <= initial_date.get_day() && are_in_the_same_month();
}

bool Simulation::are_in_the_same_month() const
{
    return date.get_month() == initial_date.get_month();
}

bool Simulation::check_to_remove(std::vector<ResidentEditor>& residents, size_t index) const
{
    return residents[index].get_resident()->get_resident_info()->get_money() <= 0 && residents[index].get_resident()->get_resident_info()->get_happiness() <= 0 && residents[index].get_resident()->get_resident_info()->get_life_points() <= 0;
}

int Simulation::simulate_day() {
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!city)
        throw std::runtime_error("City not created!");
    int removedResidents = 0;
    
    date.increment_day();
    
    std::vector<ResidentEditor>& residents = manager->get_residents();
    
    unsigned currentDay = date.get_day();
    for(int z = 0; z < residents.size(); z++){
        
        Resident* res = residents[z].get_resident();
        unsigned bornDay = res->get_resident_info()->get_born();
        int removalDay = res->get_resident_info()->get_removal_day();
        
        manager->forward(date.check_month_change(), currentDay, city, z);
        
        if (currentDay == bornDay && res->get_resident_info()->get_cause() == RemovalCause::RemovedManually && res->get_resident_info()->is_alive())
            manager->remove_resident(z, city, res->get_name());
        
        else if(currentDay == removalDay)
            manager->bring_back(city, z);
        
        if(check_to_remove(residents, z))
        {
            manager->remove_resident(city, res->get_name(), currentDay,z);
            removedResidents++;
        }
        
    }
    return removedResidents;
}


void Simulation::back_steps(int n)
{
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!city)
        throw std::runtime_error("City not created!");
    int targetDays = -n;
    for (int i = 0; i < targetDays; ++i) {
        unsigned currentDay = date.get_day();
        if (check_to_stop())
            break;
        
        std::vector<ResidentEditor>& residents = manager->get_residents();

        for (int j = 0; j < residents.size(); ++j) {
            Resident* res = residents[j].get_resident();
            unsigned bornDay = res->get_resident_info()->get_born();
            int removalDay = res->get_resident_info()->get_removal_day();

            residents[j].go_back();

            if (currentDay < bornDay && res->get_resident_info()->get_cause() == RemovalCause::None && are_in_the_same_month()) {
                manager->remove_resident(city, res->get_name(),currentDay,j);
            }
            else if (removalDay == currentDay) {
                manager->bring_back(city, j);
            }
        }
        date.decrement_day();
    }
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
    } else {
        back_steps(n);
        return -1;
    }
}

void Simulation::print_status(std::ostream& os) const {
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!city)
        throw std::runtime_error("City not created!");
    
    for (int i = 0; i < city->get_width(); i++) {
        for (int j = 0; j < city->get_height(); j++) {
            Coordinates coords(i, j);
            Building* building = city->get_building_at(coords);
            os<<"Location " << i << " " << j << ": " << std::endl;
            building->print_building(os);
            building->print_residents(os);
        }
    }
}

unsigned Simulation::get_current_day() const
{
    return date.get_day();
}


void Simulation::save_simulation_to_file(std::ofstream& ofs) const
{
    CityContext* context = CityContext::get_instance();
    City* city = context->get_city();
    if(!city)
        throw std::runtime_error("City not created!");
    city->save_city_to_file(ofs);
    manager->save_residents_to_file(ofs);
}

void Simulation::load_simulation_from_file(std::ifstream& ifs){
    CityContext* context = CityContext::get_instance();
    context->set_city(new City(ifs));
    City* city = context->get_city();
    manager->load_residents_from_file(city, ifs);
}

void Simulation::generate_city(int width, int height)
{
    CityContext* cityContext = CityContext::get_instance();
    cityContext->set_city(new City(width, height));
    City* city = cityContext->get_city();
    manager->generate_random_residents(city, date.get_day());
}

const std::string Simulation::get_date() const
{
    return date.get_current_date();
}


