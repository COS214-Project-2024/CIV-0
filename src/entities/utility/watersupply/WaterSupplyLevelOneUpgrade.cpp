#include "WaterSupplyLevelOneUpgrade.h"

WaterSupplyLevelOneUpgrade::WaterSupplyLevelOneUpgrade(WaterSupply* waterSupply) : WaterSupplyUpgrade(waterSupply) {

}

WaterSupplyLevelOneUpgrade::WaterSupplyLevelOneUpgrade(WaterSupplyLevelOneUpgrade* waterSupplyLevelOneUpgrade) : WaterSupplyUpgrade(waterSupplyLevelOneUpgrade) {

}

WaterSupplyLevelOneUpgrade::~WaterSupplyLevelOneUpgrade() {

}

void WaterSupplyLevelOneUpgrade::update() {
    waterSupply->update();
}

Entity* WaterSupplyLevelOneUpgrade::clone() {
    return new WaterSupplyLevelOneUpgrade(this);
}

int WaterSupplyLevelOneUpgrade::getOutput() {
    return waterSupply->getOutput() * UPGRADE;
}
