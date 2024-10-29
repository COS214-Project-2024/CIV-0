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
    return this;
}

int WaterSupplyLevelThreeUpgrade::getOutput() {
    return waterSupply->getOutput() * UPGRADE;
}
