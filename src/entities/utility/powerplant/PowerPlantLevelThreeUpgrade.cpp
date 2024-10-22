#include "PowerPlantLevelThreeUpgrade.h"

PowerPlantLevelThreeUpgrade::PowerPlantLevelThreeUpgrade(PowerPlant* powerPlant) : PowerPlantUpgrade(powerPlant) {

}

PowerPlantLevelThreeUpgrade::PowerPlantLevelThreeUpgrade(PowerPlantLevelThreeUpgrade* powerPlantLevelThreeUpgrade) : PowerPlantUpgrade(powerPlantLevelThreeUpgrade) {

}

PowerPlantLevelThreeUpgrade::~PowerPlantLevelThreeUpgrade() {

}

void PowerPlantLevelThreeUpgrade::update() {
    powerPlant->update();
}

Entity* PowerPlantLevelThreeUpgrade::clone() {
    return new PowerPlantLevelThreeUpgrade(this);
}

int PowerPlantLevelThreeUpgrade::getOutput() {
    return powerPlant->getOutput() * UPGRADE;
}
