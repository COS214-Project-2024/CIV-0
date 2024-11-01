#include "PowerPlantUpgrade.h"

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlant* power) : PowerPlant(power) {
    this->powerPlant = new PowerPlant(power);
}

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlantUpgrade* pPU) : PowerPlant(pPU) {
    this->powerPlant = new PowerPlant(pPU->powerPlant);
}

PowerPlantUpgrade::~PowerPlantUpgrade() {
    if(powerPlant != nullptr) {
        delete powerPlant;
        powerPlant = nullptr;
    }
}
