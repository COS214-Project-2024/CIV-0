#include "StoneProducer.h"

StoneProducer::StoneProducer() {}
StoneProducer::~StoneProducer() {}

StoneProducer::StoneProducer(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Industry(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{
    setOutput(20); //TODO - change value
}

void StoneProducer::update()
{
    //TODO
}

Entity* StoneProducer::clone()
{
    Entity* e = new StoneProducer(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}