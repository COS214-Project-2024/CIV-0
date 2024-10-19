#include "TrainStation.h"

TrainStation::TrainStation(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Transport(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

TrainStation::TrainStation() {}
TrainStation::~TrainStation() {}

void TrainStation::update()
{
    //TODO
}

Entity* TrainStation::clone()
{
    Entity* e = new TrainStation(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}
