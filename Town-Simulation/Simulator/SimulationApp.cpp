#include <stdio.h>
#include "SimulationApp.h"
SimulationApp* SimulationApp::theSimulation = nullptr;

SimulationApp::SimulationApp(const Printer* printer) : manager(new ResidentManager()) , processor(new CommandProcessor())
{
    this->printer = printer;
    sim = new Simulation(manager);
    registry = new CommandRegistry(sim, manager);
    registry->register_all_commands(*processor);
}

SimulationApp* SimulationApp::get_instance(const Printer* printer)
{
    if(theSimulation == nullptr)
        theSimulation = new SimulationApp(printer);
    return theSimulation;
}

void SimulationApp::menu() const
{
    this->printer->println(R"(

 
                    ░█████╗░██╗████████╗██╗░░░██╗  
                    ██╔══██╗██║╚══██╔══╝╚██╗░██╔╝ 
                    ██║░░╚═╝██║░░░██║░░░░╚████╔╝░  
                    ██║░░██╗██║░░░██║░░░░░╚██╔╝░░  
                    ╚█████╔╝██║░░░██║░░░░░░██║░░░  
                    ░╚════╝░╚═╝░░░╚═╝░░░░░░╚═╝░░░  

░██████╗██╗███╗░░░███╗██╗░░░██╗██╗░░░░░░█████╗░████████╗██╗░█████╗░███╗░░██╗
██╔════╝██║████╗░████║██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║
╚█████╗░██║██╔████╔██║██║░░░██║██║░░░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║
░╚═══██╗██║██║╚██╔╝██║██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║
██████╔╝██║██║░╚═╝░██║╚██████╔╝███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║
╚═════╝░╚═╝╚═╝░░░░░╚═╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝


                        Available commands:



                          Create a city:
  >> generate <n> <m>
    Creates a city with dimensions n x m with randomly generated buildings and residents.
    Outputs the date the simulation was created.
    Output: <current simulation date>


                             Add people:

  >> add <n> <m> <name> <job> <happiness> <money> <life>
    Adds a person at location (n, m) with the given characteristics.
    Output: Result of the operation (successful or unsuccessful).



                            Remove people:

  >> remove <n> <m> <name>
    Removes a person named <name> from location (n, m).
    Output: Result of the operation (successful or unsuccessful).


                           Simulation steps:

  >> step
    Advances the simulation by 1 day.
    Output: Number of people with 0 happiness, 0 life, and 0 money (removed from the simulation).
  
  >> step <n>
    Advances (or rewinds) the simulation by n days.
    Output: Number of people with 0 happiness, 0 life, and 0 money (removed from the simulation).


                         Simulation information:

  >> info
    Displays full structured information about the entire simulation.

  >> info <x> <y>
    Displays information about the building and people at location (x, y).

  >> info <x> <y> <name>
    Detailed history and characteristics of a person named <name> at location (x, y).


                              Serialization:

  >> save <name>
    Saves the current state of the simulation to a file named <name>.

  >> load <name>
    Loads a simulation from a file named <name>.

                             Exit the program:

  >> End
    Exits the simulation.

)");
    
}

void SimulationApp::run()
{
    std::string input;
    menu();
    do{
        printer->print("> ");
        
        std::getline(std::cin, input);
        if(input == "End")
        {
            printer->print("Exiting simulation. Goodbye!");
            break;
        }
        try{
            processor->process_command(input);
        }
        catch(std::runtime_error& error)
        {
            printer->println(error.what());
        }
        
        printer->println();
        printer->println("=== Input ===)");
    }
    while(true);
   
}

void SimulationApp::free_dynamic()
{
    delete sim;
    delete manager;
    delete registry;
    delete processor;
    sim = nullptr;
    manager = nullptr;
    registry = nullptr;
    processor = nullptr;
}

SimulationApp::~SimulationApp()
{
    free_dynamic();
}

void SimulationApp::destroy_instance()
{
    delete theSimulation;
    theSimulation = nullptr;
}

void SimulationApp::shutdown() {
    BuildingFactory::destroy_instance();
    ProfessionFactory::destroy_instance();
    destroy_instance();
}
