#include "PowerPlantLevelThreeUpgrade.h"

PowerPlantLevelThreeUpgrade::PowerPlantLevelThreeUpgrade(PowerPlant* power) : PowerPlantUpgrade(power) {

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

Entity* PowerPlantLevelThreeUpgrade::upgrade() {
    // Maximum level reached
    return this;
}

int PowerPlantLevelThreeUpgrade::getOutput() {
    return powerPlant->getOutput() * UPGRADE;
}
