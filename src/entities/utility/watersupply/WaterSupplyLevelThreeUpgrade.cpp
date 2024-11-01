#include "WaterSupplyLevelThreeUpgrade.h"

WaterSupplyLevelThreeUpgrade::WaterSupplyLevelThreeUpgrade(WaterSupply *water) : WaterSupplyUpgrade(water)
{
}

WaterSupplyLevelThreeUpgrade::WaterSupplyLevelThreeUpgrade(WaterSupplyLevelThreeUpgrade *wSLTU) : WaterSupplyUpgrade(wSLTU)
{
}

WaterSupplyLevelThreeUpgrade::~WaterSupplyLevelThreeUpgrade()
{
}

void WaterSupplyLevelThreeUpgrade::update()
{
    waterSupply->update();
}

int WaterSupplyLevelThreeUpgrade::getLevel()
{
    return 3;
}

Entity *WaterSupplyLevelThreeUpgrade::clone()
{
    return new WaterSupplyLevelThreeUpgrade(this);
}

Entity *WaterSupplyLevelThreeUpgrade::upgrade()
{
    // Maximum level reached
    return nullptr;
}

int WaterSupplyLevelThreeUpgrade::getOutput()
{
    return waterSupply->getOutput() * UPGRADE;
}

Cost WaterSupplyLevelThreeUpgrade::getCost()
{
    return Cost(waterSupply->getCost().moneyCost * UPGRADE, waterSupply->getCost().woodCost * UPGRADE, waterSupply->getCost().stoneCost * UPGRADE, waterSupply->getCost().concreteCost * UPGRADE);
}