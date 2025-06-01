#include "City.h"
#include "ResidentManager.h"
#include "GenerateCommand.h"

int main() {
    City* test = new City(10,10);
    GenerateCommand command(test);
    std::vector<std::string> vec = {"10", "10"};
    command.execute(vec);
    return 0;
}
