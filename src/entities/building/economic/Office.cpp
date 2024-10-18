#include "Office.h"

Office::Office() {}
Office::~Office() {}

Office::Office(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : EconomicBuilding(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

void Office::update()
{
    //TODO
}

Entity* Office::clone()
{
    Entity* e = new Office(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}
