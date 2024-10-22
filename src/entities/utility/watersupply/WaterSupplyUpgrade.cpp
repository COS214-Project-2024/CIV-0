#include "WaterSupplyUpgrade.h"

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupply* waterSupply) : WaterSupply(waterSupply) {
    this->waterSupply = waterSupply;
}

WaterSupplyUpgrade::WaterSupplyUpgrade(WaterSupplyUpgrade* waterSupplyUpgrade) : WaterSupply(waterSupplyUpgrade) {
    this->waterSupply = waterSupplyUpgrade->waterSupply;
}

WaterSupplyUpgrade::~WaterSupplyUpgrade() {
    
}
