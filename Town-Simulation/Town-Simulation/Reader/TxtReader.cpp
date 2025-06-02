#include <stdio.h>
#include "TxtReader.h"
#include "CityContext.h"
#include "LocationFactory.h"
#include "BuildingFactory.h"
#include <fstream>

TxtReader::TxtReader(const std::string& fileName) : Reader(fileName) {}

void TxtReader::read(Simulation* sim) {}
/*{
    std::ifstream file;
    file.open(fileName);
    if (!file.is_open())
        throw std::runtime_error("File could not open!");

    CityContext* context = CityContext::get_instance();
    
    int width, height;
    file >> width >> height;
    file.ignore(); // skip to the next line

    std::vector<std::vector<Building*>> grid(height, std::vector<Building*>(width, nullptr));

    std::string line;
    while (std::getline(file, line))
    {
        // Directly check for "Location" as there are no leading whitespaces
        if (line.substr(0, 8) == "Location")
        {
            int x, y;
            std::istringstream iss(line);
            std::string label;
            iss >> label >> x >> y;
            LocationFactory factory(x, y);
            Location* location = factory.create_location(x, y);
            
            BuildingType buildingType = BuildingType::Modern;

            if (!std::getline(file, line)) break;
            if (line == "Modern")
                buildingType = BuildingType::Modern;
            else if (line == "PanelBlock")
                buildingType = BuildingType::PanelBlock;
            else if (line == "Dormitory")
                buildingType = BuildingType::Dormitory;

            Building* building = BuildingFactory::get_factory()->create_building(buildingType, location);
            if (!building) continue;

            grid[y][x] = building;

            // Read location type
            if (!std::getline(file, line)) break;
            if (line == "Central")
                building->get_location()->set_type(LocationType::Central);
            else if (line == "Peripheral")
                building->get_location()->set_type(LocationType::Peripheral);
            else
                building->get_location()->set_type(LocationType::Unknown);

            // Read residents
            while (std::getline(file, line))
            {
                if (line.empty() || line.substr(0, 8) == "Location")
                {
                    if (line.substr(0, 8) == "Location")
                    {
                        // Move file pointer back so outer while can process this line
                        file.seekg(-static_cast<int>(line.length()) - 1, std::ios_base::cur);
                    }
                    break;
                }

                // Read resident name (format: "0: John")
                size_t idx = 0;
                while (idx < line.size() && line[idx] != ':') ++idx;
                std::string name = line.substr(idx + 2);
                Resident* resident = new Resident(name);

                // Read profession
                if (!std::getline(file, line)) break;
                idx = 0;
                while (idx < line.size() && line[idx] != ':') ++idx;
                std::string professionType = line.substr(idx + 2);
                resident->set_profession_from_string(professionType);

                // Read happiness
                if (!std::getline(file, line)) break;
                idx = 0;
                while (idx < line.size() && line[idx] != ':') ++idx;
                int happiness = std::stoi(line.substr(idx + 2));

                // Read money
                if (!std::getline(file, line)) break;
                idx = 0;
                while (idx < line.size() && line[idx] != ':') ++idx;
                int money = std::stoi(line.substr(idx + 2));

                // Read life
                if (!std::getline(file, line)) break;
                idx = 0;
                while (idx < line.size() && line[idx] != ':') ++idx;
                int life = std::stoi(line.substr(idx + 2));

                resident->get_info().set_happiness(happiness);
                resident->get_info().set_money(money);
                resident->get_info().set_life_points(life);

                building->add_resident(resident);
            }
        }
    }
    context->create_city(width, height, grid);
}
*/
