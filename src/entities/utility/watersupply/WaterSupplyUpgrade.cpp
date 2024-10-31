#include "WaterSupplyUpgrade.h"

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupply* water) : WaterSupply(water) {
    this->waterSupply = new WaterSupply(water);
}

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupplyUpgrade* waterSupplyUpgrade) : WaterSupply(waterSupplyUpgrade) {
    this->waterSupply = new WaterSupply(waterSupplyUpgrade->waterSupply);
}

WaterSupplyUpgrade::~WaterSupplyUpgrade() {
    if(waterSupply != nullptr) {
        delete waterSupply;
        waterSupply = nullptr;
    }
}