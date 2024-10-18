#include "SewageSystem.h"

SewageSystem::SewageSystem(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(20, electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    //TODO - change value of output (1st param in utility constructor)
}

SewageSystem::SewageSystem(SewageSystem* sewageSystem) : Utility(sewageSystem) {

}

SewageSystem::~SewageSystem() {

}

void SewageSystem::update() {
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* SewageSystem::clone() {
    return new SewageSystem(this);
}