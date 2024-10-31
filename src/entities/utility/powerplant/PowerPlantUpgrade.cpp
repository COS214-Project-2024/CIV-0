#include "PowerPlantUpgrade.h"

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlant* power) : PowerPlant(power) {
    this->powerPlant = new PowerPlant(power);
}

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlantUpgrade* powerPlantUpgrade) : PowerPlant(powerPlantUpgrade) {
    this->powerPlant = new PowerPlant(powerPlantUpgrade->powerPlant);
}

PowerPlantUpgrade::~PowerPlantUpgrade() {
    if(powerPlant != nullptr) {
        delete powerPlant;
        powerPlant = nullptr;
    }
}
