#include "WoodProducer.h"

WoodProducer::WoodProducer() {}
WoodProducer::~WoodProducer() {}

WoodProducer::WoodProducer(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Industry(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{
    setOutput(20); //TODO - change value
}

void WoodProducer::update()
{
    //TODO
}

Entity* WoodProducer::clone()
{
    Entity* e = new WoodProducer(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}