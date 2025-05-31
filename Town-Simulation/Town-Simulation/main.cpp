#include <iostream>
#include "BuildingFactory.h"
#include "LocationFactory.h"
#include "ProfessionFactory.h"
#include "Resident.h"
#include "City.h"
#include "ResidentManager.h"


int main() {
    BuildingFactory* factory = BuildingFactory::get_factory();

    const int testCapacity = 10;
    
    ResidentManager rs;
   
    
    LocationFactory locFactory(10, 10);
    Location* loc1 = locFactory.create_location(2, 2);
    Location* loc2 = locFactory.create_location(3, 3);
    Location* loc3 = locFactory.create_location(4, 4);


    Building* modern = factory->create_building(BuildingType::Modern, loc1, testCapacity);
    Building* dorm = factory->create_building(BuildingType::Dormitory, loc2, testCapacity);
    Building* panel = factory->create_building(BuildingType::PanelBlock, loc3, testCapacity);
    
    
    City city(10,10);
    city.add_building(2, 2, modern);
    city.add_building(3, 3, dorm);
    city.add_building(4, 4, panel);
    
    
    
    
    std::cout << "== Building Factory Test ==" << std::endl;

    std::cout << "\n== Profession Factory Test ==" << std::endl;
    ProfessionFactory* profFactory = ProfessionFactory::get_factory();

    std::string pr1("Teacher");
    std::string pr2("Programmer");
    std::string pr3("Unknown");
    
    Profession* teacher = profFactory->create_profession(pr1);
    Profession* engineer = profFactory->create_profession(pr2);
    Profession* unknown = profFactory->create_profession(pr3);

    if (teacher)
        std::cout << "✅ Teacher profession created.\n";
    else
        std::cout << "❌ Teacher profession failed.\n";

    if (engineer)
        std::cout << "✅ Engineer profession created.\n";
    else
        std::cout << "❌ Engineer profession failed.\n";

    if (!unknown)
        std::cout << "✅ Unknown profession correctly failed.\n";
    else
        std::cout << "❌ Unknown profession should not exist.\n";


    std::cout << "\n== Resident Test ==" << std::endl;
    
    std::string r1("name1");
    std::string r2("name2");
    std::string r3("name3");
    
    resident_info managerInfo(80, 2000.0, 100);
    Resident* res1 = new Resident(r1, teacher, managerInfo, modern);
    Resident* res2 = new Resident(r2,engineer, managerInfo, modern);

    std::cout << "Resident 1: " <<std::endl;
    res1->print_info();
    std::cout << "Resident 2: "  << std::endl;
    res2->print_info();

    if (modern)
        std::cout << "✅ ModernBuilding created.\n";
    else
        std::cout << "❌ ModernBuilding failed.\n";

    if (dorm)
        std::cout << "✅ DormitoryBuilding created.\n";
    else
        std::cout << "❌ DormitoryBuilding failed.\n";

    if (panel)
        std::cout << "✅ PanelBlockBuilding created.\n";
    else
        std::cout << "❌ PanelBlockBuilding failed.\n";
    
    rs.addResident(city, 2, 2, res1);
    rs.removeResident(city, 2, 2, "name1");
    rs.addResident(city, 2, 2, res2);
    
    return 0;
}
