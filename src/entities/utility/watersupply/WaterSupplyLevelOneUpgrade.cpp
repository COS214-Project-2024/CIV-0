#include "WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"

WaterSupplyLevelOneUpgrade::WaterSupplyLevelOneUpgrade(WaterSupply *water) : WaterSupplyUpgrade(water)
{
}

WaterSupplyLevelOneUpgrade::WaterSupplyLevelOneUpgrade(WaterSupplyLevelOneUpgrade *wSLOU) : WaterSupplyUpgrade(wSLOU)
{
}

WaterSupplyLevelOneUpgrade::~WaterSupplyLevelOneUpgrade()
{
}

void WaterSupplyLevelOneUpgrade::update()
{
    waterSupply->update();
}

int WaterSupplyLevelOneUpgrade::getLevel()
{
    return 1;
}

Entity *WaterSupplyLevelOneUpgrade::clone()
{
    return new WaterSupplyLevelOneUpgrade(this);
}

Entity *WaterSupplyLevelOneUpgrade::upgrade()
{
    return new WaterSupplyLevelTwoUpgrade(waterSupply);
}

int WaterSupplyLevelOneUpgrade::getOutput()
{
    return waterSupply->getOutput() * UPGRADE;
}

Cost WaterSupplyLevelOneUpgrade::getCost()
{
    return Cost(waterSupply->getCost().moneyCost * UPGRADE, waterSupply->getCost().woodCost * UPGRADE, waterSupply->getCost().stoneCost * UPGRADE, waterSupply->getCost().concreteCost * UPGRADE);
}