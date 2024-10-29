#include "WaterSupplyLevelOneUpgrade.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"

WaterSupplyLevelOneUpgrade::WaterSupplyLevelOneUpgrade(WaterSupply* water) : WaterSupplyUpgrade(water) {

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

Entity* WaterSupplyLevelOneUpgrade::upgrade() {
    return new WaterSupplyLevelTwoUpgrade(waterSupply);
}

int WaterSupplyLevelOneUpgrade::getOutput() {
    return waterSupply->getOutput() * UPGRADE;
}
