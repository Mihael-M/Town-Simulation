#include <stdio.h>
#include "MinerCreator.h"
#include "Miner.h"

MinerCreator::MinerCreator() : ProfessionCreator("Miner") {}

Profession* MinerCreator::create_profession(const std::string& type) const
{
    return new Miner(type);
}
