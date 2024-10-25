#include "PowerPlantUpgrade.h"

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlant* powerPlant) : PowerPlant(powerPlant) {
    this->powerPlant = powerPlant;
}

PowerPlantUpgrade::PowerPlantUpgrade(PowerPlantUpgrade* powerPlantUpgrade) : PowerPlant(powerPlantUpgrade) {
    this->powerPlant = powerPlantUpgrade->powerPlant;
}

PowerPlantUpgrade::~PowerPlantUpgrade() {

}