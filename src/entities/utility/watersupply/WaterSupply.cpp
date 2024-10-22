#include "WaterSupply.h"

WaterSupply::WaterSupply(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(20, electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    //TODO - change value of output (1st param in Utility constructor)
}

WaterSupply::WaterSupply(WaterSupply* waterSupply) : Utility(waterSupply) {

}

WaterSupply::WaterSupply() : Utility() {

}

WaterSupply::~WaterSupply() {

}

void WaterSupply::update() {
    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* WaterSupply::clone() {
    return new WaterSupply(this);
}