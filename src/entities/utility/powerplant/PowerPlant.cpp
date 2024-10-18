#include "PowerPlant.h"

PowerPlant::PowerPlant(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(20, electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    //TODO - change value of output (1st param in utility constructor)
}

PowerPlant::PowerPlant(PowerPlant* powerPlant) : Utility(powerPlant) {

}

PowerPlant::~PowerPlant() {}

void PowerPlant::update() {
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* PowerPlant::clone() {
    return new PowerPlant(this);
}