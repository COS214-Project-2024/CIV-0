#include "WaterSupplyLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelThreeUpgrade.h"

WaterSupplyLevelTwoUpgrade::WaterSupplyLevelTwoUpgrade(WaterSupply *water) : WaterSupplyUpgrade(water)
{
}

WaterSupplyLevelTwoUpgrade::WaterSupplyLevelTwoUpgrade(WaterSupplyLevelTwoUpgrade *waterSupplyLevelTwoUpgrade) : WaterSupplyUpgrade(waterSupplyLevelTwoUpgrade)
{
}

WaterSupplyLevelTwoUpgrade::~WaterSupplyLevelTwoUpgrade()
{
}

void WaterSupplyLevelTwoUpgrade::update()
{
    waterSupply->update();
}

int WaterSupplyLevelTwoUpgrade::getLevel()
{
    return 2;
}

Entity *WaterSupplyLevelTwoUpgrade::clone()
{
    return new WaterSupplyLevelTwoUpgrade(this);
}

Entity *WaterSupplyLevelTwoUpgrade::upgrade()
{
    return new WaterSupplyLevelThreeUpgrade(waterSupply);
}

int WaterSupplyLevelTwoUpgrade::getOutput()
{
    return waterSupply->getOutput() * UPGRADE;
}

Cost WaterSupplyLevelTwoUpgrade::getCost()
{
    return Cost(waterSupply->getCost().moneyCost * UPGRADE, waterSupply->getCost().woodCost * UPGRADE, waterSupply->getCost().stoneCost * UPGRADE, waterSupply->getCost().concreteCost * UPGRADE);
}