#include "Airport.h"

Airport::Airport(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Transport(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

Airport::Airport() {}
Airport::~Airport() {}

void Airport::update()
{
    //TODO
}

Entity* Airport::clone()
{
    Entity* e = new Airport(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}
