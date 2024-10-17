#include "PoliceStation.h"

PoliceStation::PoliceStation() {}
PoliceStation::~PoliceStation() {}

PoliceStation::PoliceStation(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : ServiceBuilding(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

void PoliceStation::update()
{
    //TODO
}

Entity* PoliceStation::clone()
{
    Entity* e = new PoliceStation(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}