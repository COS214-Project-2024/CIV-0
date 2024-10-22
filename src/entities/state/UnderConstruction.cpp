#include "UnderConstruction.h"
#include "Built.h"

UnderConstruction::UnderConstruction(int buildTime) : State(buildTime) {}
UnderConstruction::UnderConstruction(UnderConstruction* underConstruction) : State(underConstruction) {}
UnderConstruction::~UnderConstruction() {}

State* UnderConstruction::update()
{
    incrementGameLoopCounter();
    if(this->getGameLoopCounter() < this->getBuildTime())
    {
        return this;
    }
    else
    {
        return new Built(getBuildTime());
    }
}

State* UnderConstruction::clone()
{
    return new UnderConstruction(this);
}