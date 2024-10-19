#include "Factory.h"

Factory::Factory() {}
Factory::~Factory() {}

Factory::Factory(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : EconomicBuilding(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

void Factory::update()
{
    //TODO
}

Entity* Factory::clone()
{
    Entity* e = new Factory(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}