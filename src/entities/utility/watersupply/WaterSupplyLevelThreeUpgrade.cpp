#include "WaterSupplyLevelThreeUpgrade.h"

WaterSupplyLevelThreeUpgrade::WaterSupplyLevelThreeUpgrade(WaterSupply* water) : WaterSupplyUpgrade(water) {

}

WaterSupplyLevelThreeUpgrade::WaterSupplyLevelThreeUpgrade(WaterSupplyLevelThreeUpgrade* waterSupplyLevelThreeUpgrade) : WaterSupplyUpgrade(waterSupplyLevelThreeUpgrade) {

}

WaterSupplyLevelThreeUpgrade::~WaterSupplyLevelThreeUpgrade() {
    
}

void WaterSupplyLevelThreeUpgrade::update() {
    waterSupply->update();
}

Entity* WaterSupplyLevelThreeUpgrade::clone() {
    return new WaterSupplyLevelThreeUpgrade(this);
}

Entity* WaterSupplyLevelThreeUpgrade::upgrade() {
    // Maximum level reached
    return this;
}

int WaterSupplyLevelThreeUpgrade::getOutput() {
    return waterSupply->getOutput() * UPGRADE;
}

Cost WaterSupplyLevelThreeUpgrade::getCost() {
    return Cost(waterSupply->getCost().moneyCost*UPGRADE, waterSupply->getCost().woodCost*UPGRADE, waterSupply->getCost().stoneCost*UPGRADE, waterSupply->getCost().concreteCost*UPGRADE);
}