#include <stdio.h>

#include "CommandRegistry.h"
#include "AddResidentCommand.h"
#include "RemoveResidentCommand.h"
#include "SaveCommand.h"
#include "StepCommand.h"
#include "StepsCommand.h"
#include "ResidentInfoCommand.h"
#include "LoadCommand.h"
#include "GenerateCommand.h"
#include "BuildingInfoCommand.h"
#include "InfoCommand.h"

CommandRegistry::CommandRegistry(Simulation* sim, ResidentManager* manager) : sim(sim), manager(manager) {}

void CommandRegistry::register_all_commands(CommandProcessor& processor) {
    processor.register_command("generate", Constants::GENERATE_CITY_ARGUMENTS, new GenerateCommand(sim));
    processor.register_command("add", Constants::ADD_RESIDENT_ARGUMENTS ,new AddResidentCommand(manager));
    processor.register_command("remove", Constants::REMOVE_RESIDENT_ARGUMENTS , new RemoveResidentCommand(manager));
    processor.register_command("step", Constants::STEP_ARGUMENTS, new StepCommand(sim));
    processor.register_command("step", Constants::STEPS_ARGUMENTS, new StepsCommand(sim));
    processor.register_command("info", Constants::INFO_ARGUMENTS, new InfoCommand(sim));
    processor.register_command("info", Constants::BUILDING_INFO_ARGUMENTS, new BuildingInfoCommand());
    processor.register_command("info", Constants::RESIDENT_INFO_ARGUMENTS, new ResidentInfoCommand());
    processor.register_command("save", Constants::SAVE_ARGUMENTS, new SaveCommand(sim));
    processor.register_command("load", Constants::LOAD_ARGUMENTS, new LoadCommand(sim));

}
