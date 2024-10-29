#include "PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelThreeUpgrade.h"

PowerPlantLevelTwoUpgrade::PowerPlantLevelTwoUpgrade(PowerPlant* power) : PowerPlantUpgrade(power) {

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

Entity* PowerPlantLevelTwoUpgrade::upgrade() {
    return new PowerPlantLevelThreeUpgrade(powerPlant);
}

int PowerPlantLevelTwoUpgrade::getOutput() {
    return powerPlant->getOutput() * UPGRADE;
}
