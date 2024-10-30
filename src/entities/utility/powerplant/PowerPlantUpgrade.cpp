#include "PowerPlantUpgrade.h"

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlant* power) : PowerPlant(power) {
    this->powerPlant = power;
}

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlantUpgrade* powerPlantUpgrade) : PowerPlant(powerPlantUpgrade) {
    this->powerPlant = powerPlantUpgrade->powerPlant;
}

PowerPlantUpgrade::~PowerPlantUpgrade() {

}
