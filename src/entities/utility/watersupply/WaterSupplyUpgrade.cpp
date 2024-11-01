#include "WaterSupplyUpgrade.h"

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupply* water) : WaterSupply(water) {
    this->waterSupply = new WaterSupply(water);
}

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupplyUpgrade* wSU) : WaterSupply(wSU) {
    this->waterSupply = new WaterSupply(wSU->waterSupply);
}

WaterSupplyUpgrade::~WaterSupplyUpgrade() {
    if(waterSupply != nullptr) {
        delete waterSupply;
        waterSupply = nullptr;
    }
}