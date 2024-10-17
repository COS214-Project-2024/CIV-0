#include "Hospital.h"

Hospital::Hospital() {}
Hospital::~Hospital() {}

Hospital::Hospital(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : ServiceBuilding(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

void Hospital::update()
{
    //TODO
}

Entity* Hospital::clone()
{
    Entity* e = new Hospital(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}