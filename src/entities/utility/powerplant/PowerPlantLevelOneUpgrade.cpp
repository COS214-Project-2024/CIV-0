#include "PowerPlantLevelOneUpgrade.h"

PowerPlantLevelOneUpgrade::PowerPlantLevelOneUpgrade(PowerPlant* powerPlant) : PowerPlantUpgrade(powerPlant) {

}

PowerPlantLevelOneUpgrade::PowerPlantLevelOneUpgrade(PowerPlantLevelOneUpgrade* powerPlantLevelOneUpgrade) : PowerPlantUpgrade(powerPlantLevelOneUpgrade) {

}

PowerPlantLevelOneUpgrade::~PowerPlantLevelOneUpgrade() {

}

void PowerPlantLevelOneUpgrade::update() {
    powerPlant->update();
}

Entity* PowerPlantLevelOneUpgrade::clone() {
    return new PowerPlantLevelOneUpgrade(this);
}

int PowerPlantLevelOneUpgrade::getOutput() {
    return powerPlant->getOutput() * UPGRADE;
}
