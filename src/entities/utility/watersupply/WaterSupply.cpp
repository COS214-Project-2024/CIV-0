#include "WaterSupply.h"

WaterSupply::WaterSupply(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(20, electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    //TODO - change value of output (1st param in utility constructor)
}

WaterSupply::WaterSupply(WaterSupply* waterSupply) : Utility(waterSupply) {

}

WaterSupply::~WaterSupply() {

}

void WaterSupply::update() {
    
}

Entity* WaterSupply::clone() {
    return new WaterSupply(this);
}