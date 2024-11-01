#include "PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"

PowerPlantLevelTwoUpgrade::PowerPlantLevelTwoUpgrade(PowerPlant *power) : PowerPlantUpgrade(power)
{
}

PowerPlantLevelTwoUpgrade::PowerPlantLevelTwoUpgrade(PowerPlantLevelTwoUpgrade *pPLTU) : PowerPlantUpgrade(pPLTU)
{
}

PowerPlantLevelTwoUpgrade::~PowerPlantLevelTwoUpgrade()
{
}

void PowerPlantLevelTwoUpgrade::update()
{
    powerPlant->update();
}

int PowerPlantLevelTwoUpgrade::getLevel()
{
    return 2;
}

Entity *PowerPlantLevelTwoUpgrade::clone()
{
    return new PowerPlantLevelTwoUpgrade(this);
}

Entity *PowerPlantLevelTwoUpgrade::upgrade()
{
    return new PowerPlantLevelThreeUpgrade(powerPlant);
}

int PowerPlantLevelTwoUpgrade::getOutput()
{
    return powerPlant->getOutput() * UPGRADE;
}

Cost PowerPlantLevelTwoUpgrade::getCost()
{
    return Cost(powerPlant->getCost().moneyCost * UPGRADE, powerPlant->getCost().woodCost * UPGRADE, powerPlant->getCost().stoneCost * UPGRADE, powerPlant->getCost().concreteCost * UPGRADE);
}