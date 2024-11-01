#include "PowerPlantLevelThreeUpgrade.h"

PowerPlantLevelThreeUpgrade::PowerPlantLevelThreeUpgrade(PowerPlant *power) : PowerPlantUpgrade(power)
{
}

PowerPlantLevelThreeUpgrade::PowerPlantLevelThreeUpgrade(PowerPlantLevelThreeUpgrade *powerPlantLevelThreeUpgrade) : PowerPlantUpgrade(powerPlantLevelThreeUpgrade)
{
}

PowerPlantLevelThreeUpgrade::~PowerPlantLevelThreeUpgrade()
{
}

void PowerPlantLevelThreeUpgrade::update()
{
    powerPlant->update();
}

int PowerPlantLevelThreeUpgrade::getLevel()
{
    return 3;
}

Entity *PowerPlantLevelThreeUpgrade::clone()
{
    return new PowerPlantLevelThreeUpgrade(this);
}

Entity *PowerPlantLevelThreeUpgrade::upgrade()
{
    // Maximum level reached
    return nullptr;
}

int PowerPlantLevelThreeUpgrade::getOutput()
{
    return powerPlant->getOutput() * UPGRADE;
}

Cost PowerPlantLevelThreeUpgrade::getCost()
{
    return Cost(powerPlant->getCost().moneyCost * UPGRADE, powerPlant->getCost().woodCost * UPGRADE, powerPlant->getCost().stoneCost * UPGRADE, powerPlant->getCost().concreteCost * UPGRADE);
}