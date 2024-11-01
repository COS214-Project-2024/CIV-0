#include "PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"

PowerPlantLevelOneUpgrade::PowerPlantLevelOneUpgrade(PowerPlant *power) : PowerPlantUpgrade(power)
{
}

PowerPlantLevelOneUpgrade::PowerPlantLevelOneUpgrade(PowerPlantLevelOneUpgrade *powerPlantLevelOneUpgrade) : PowerPlantUpgrade(powerPlantLevelOneUpgrade)
{
}

PowerPlantLevelOneUpgrade::~PowerPlantLevelOneUpgrade()
{
}

void PowerPlantLevelOneUpgrade::update()
{
    powerPlant->update();
}

int PowerPlantLevelOneUpgrade::getLevel()
{
    return 1;
}

Entity *PowerPlantLevelOneUpgrade::clone()
{
    return new PowerPlantLevelOneUpgrade(this);
}

Entity *PowerPlantLevelOneUpgrade::upgrade()
{
    return new PowerPlantLevelTwoUpgrade(powerPlant);
}

int PowerPlantLevelOneUpgrade::getOutput()
{
    return powerPlant->getOutput() * UPGRADE;
}

Cost PowerPlantLevelOneUpgrade::getCost()
{
    return Cost(powerPlant->getCost().moneyCost * UPGRADE, powerPlant->getCost().woodCost * UPGRADE, powerPlant->getCost().stoneCost * UPGRADE, powerPlant->getCost().concreteCost * UPGRADE);
}
