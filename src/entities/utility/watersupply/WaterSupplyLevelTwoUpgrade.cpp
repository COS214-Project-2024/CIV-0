#include "WaterSupplyLevelTwoUpgrade.h"

WaterSupplyLevelTwoUpgrade::WaterSupplyLevelTwoUpgrade(WaterSupply* waterSupply) : WaterSupplyUpgrade(waterSupply) {

}

WaterSupplyLevelTwoUpgrade::WaterSupplyLevelTwoUpgrade(WaterSupplyLevelTwoUpgrade* waterSupplyLevelTwoUpgrade) : WaterSupplyUpgrade(waterSupplyLevelTwoUpgrade) {

}

WaterSupplyLevelTwoUpgrade::~WaterSupplyLevelTwoUpgrade() {
    
}

void WaterSupplyLevelTwoUpgrade::update() {
    waterSupply->update();
}

Entity* WaterSupplyLevelTwoUpgrade::clone() {
    return new WaterSupplyLevelTwoUpgrade(this);
}

int WaterSupplyLevelTwoUpgrade::getOutput() {
    return waterSupply->getOutput() * UPGRADE;
}
