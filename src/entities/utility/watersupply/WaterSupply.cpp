#include "WaterSupply.h"

WaterSupply::WaterSupply() {}
WaterSupply::~WaterSupply() {}

WaterSupply::WaterSupply(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Utility(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{
    setOutput(20); //TODO - change value
}

void WaterSupply::update()
{
    //TODO
}

Entity* WaterSupply::clone()
{
    Entity* e = new WaterSupply(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}