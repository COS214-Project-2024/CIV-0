#include "WaterSupplyLevelThreeUpgrade.h"

WaterSupplyLevelThreeUpgrade::WaterSupplyLevelThreeUpgrade(WaterSupply* waterSupply) : WaterSupplyUpgrade(waterSupply) {

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

int WaterSupplyLevelThreeUpgrade::getOutput() {
    return waterSupply->getOutput() * UPGRADE;
}
