#include <stdio.h>
#include "Simulation.h"
#include <iostream>

void Simulation::simulate_day() {
    for (int i = 0; i < city->get_height(); i++) {
        for (int j = 0; j < city->get_width(); j++) {
            Building* building = city->get_building_at(i, j);
                auto residents = building->get_residents();
                residents.erase(std::remove_if(residents.begin(), residents.end(),
                    [](const Resident* r) {
                        return r->get_resident_info().get_money() <= 0 || r->get_resident_info().get_happiness() <= 0 || r->get_resident_info().get_life_points() <= 0;
                    }), residents.end());
            }
        }
    currentDay++;
}
   


void Simulation::simulate_month() {
    for (int day = 0; day < 30; day++) {
        simulate_day();
    }
    for (int i = 0; i < city->get_height(); i++) {
        for (int j = 0; j < city->get_width(); j++) {
            Building* building = city->get_building_at(i, j);
            if (building != nullptr) {
                auto residents = building->get_residents();
                for (Resident* r : residents) {
                    r->receive_salary();
                }
            }
        }
    }
}

void Simulation::print_status() const {
    for (int i = 0; i < city->get_height(); i++) {
        for (int j = 0; j < city->get_width(); j++) {
            Building* building = city->get_building_at(i, j);
            if (building != nullptr) {
                std::cout<< "\n";
                std::cout << "Residents: ";
                auto residents = building->get_residents();
                for (const Resident* r : residents) {
                    std::cout << r->get_name() << " ";
                }
                std::cout << "\n";
            }
        }
    }
}


