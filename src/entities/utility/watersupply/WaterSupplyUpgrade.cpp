#include "WaterSupplyUpgrade.h"

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupply* water) : WaterSupply(water) {
    this->waterSupply = water;
}

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupplyUpgrade* waterSupplyUpgrade) : WaterSupply(waterSupplyUpgrade) {
    this->waterSupply = waterSupplyUpgrade->waterSupply;
}

WaterSupplyUpgrade::~WaterSupplyUpgrade() {
    
}
