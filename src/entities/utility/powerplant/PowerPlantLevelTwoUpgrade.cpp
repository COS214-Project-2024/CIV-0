#include "PowerPlantLevelTwoUpgrade.h"

PowerPlantLevelTwoUpgrade::PowerPlantLevelTwoUpgrade(PowerPlant* powerPlant) : PowerPlantUpgrade(powerPlant) {

}

PowerPlantLevelTwoUpgrade::PowerPlantLevelTwoUpgrade(PowerPlantLevelTwoUpgrade* powerPlantLevelTwoUpgrade) : PowerPlantUpgrade(powerPlantLevelTwoUpgrade) {

}

PowerPlantLevelTwoUpgrade::~PowerPlantLevelTwoUpgrade() {

}

void PowerPlantLevelTwoUpgrade::update() {
    powerPlant->update();
}

Entity* PowerPlantLevelTwoUpgrade::clone() {
    return new PowerPlantLevelTwoUpgrade(this);
}

int PowerPlantLevelTwoUpgrade::getOutput() {
    return powerPlant->getOutput() * UPGRADE;
}