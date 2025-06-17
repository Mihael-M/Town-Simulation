#include "ResidentEditor.h"
#include <iostream>

ResidentEditor::ResidentEditor(Resident* resident){
    this->resident = resident;
}


void ResidentEditor::go_forward(bool isFirstDayOfMonth, int currentDay, Building* building){
    stateHistory.push_back(resident->take_snapshot());
    resident->live_day(isFirstDayOfMonth, currentDay, building);
}


void ResidentEditor::go_back(){
    if (!stateHistory.empty()) {
        resident->restore(stateHistory.back());
        delete stateHistory.back();
        stateHistory.pop_back();
    }
}

void ResidentEditor::free_dynamic(){
    const size_t size = stateHistory.size();
    
    for(int i = 0;i<size;i++)
        delete stateHistory[i];
    
    stateHistory.clear();
}

ResidentEditor::~ResidentEditor(){
    free_dynamic();
}

ResidentEditor::ResidentEditor(const ResidentEditor& other) : resident(other.resident){
    copy_dynamic(other);
}

ResidentEditor& ResidentEditor::operator=(const ResidentEditor& other){
    if (this != &other){
        resident = other.resident;
        free_dynamic();
        copy_dynamic(other);
    }
    return *this;
}

void ResidentEditor::copy_dynamic(const ResidentEditor& other){
    const size_t size = other.stateHistory.size();
    
    for(int i = 0;i<size;i++)
        stateHistory.push_back(new Resident::ResidentMemento(*other.stateHistory[i]));
}

void ResidentEditor::print_memento(std::ostream& os, size_t i) const {
    os << "Profession: " << stateHistory[i]->get_profession()->get_type()
       << ", Happiness: " << stateHistory[i]->get_info()->get_happiness()
       << ", Money: " << stateHistory[i]->get_info()->get_money()
       << ", Life Points: " << stateHistory[i]->get_info()->get_life_points()
       << std::endl;
}

void ResidentEditor::print_history(std::ostream& os) const
{
    
    for(int i = 0; i < stateHistory.size(); i++)
    {
        std::cout<< i + 1 << ": ";
        print_memento(os, i);
            
    }
    
}

void ResidentEditor::save_memento_to_file(std::ofstream& ofs) const
{
    resident->save_to_file(ofs);
    size_t size = stateHistory.size();
    ofs<< size <<std::endl;
    for(int i = 0; i < size; i++)
    {
        save_memento_to_file(ofs, i);
    }
}
void ResidentEditor::save_memento_to_file(std::ofstream& ofs, size_t i) const
{
    ofs<<stateHistory[i]->get_name()<<std::endl;
    ofs<<stateHistory[i]->get_profession()->get_type()<<std::endl;
    stateHistory[i]->get_info()->save_info_to_file(ofs);
}

ResidentEditor::ResidentEditor(std::ifstream& ifs)
{
    load_memento_from_file(ifs);
}

void ResidentEditor::load_memento_from_file(std::ifstream& ifs)
{
    resident = new Resident(ifs);
    size_t size;
    ifs>>size;
    for(int i = 0;i<size;i++)
        stateHistory.push_back(resident->load_memento_from_file(ifs));
}

Resident* ResidentEditor::get_resident() const
{
    return resident;
}
