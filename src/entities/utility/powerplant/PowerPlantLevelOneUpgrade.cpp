#include "PowerPlantLevelOneUpgrade.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"

PowerPlantLevelOneUpgrade::PowerPlantLevelOneUpgrade(PowerPlant* power) : PowerPlantUpgrade(power) {

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

Entity* PowerPlantLevelOneUpgrade::upgrade() {
    return new PowerPlantLevelTwoUpgrade(powerPlant);
}

int PowerPlantLevelOneUpgrade::getOutput() {
    return powerPlant->getOutput() * UPGRADE;
}
