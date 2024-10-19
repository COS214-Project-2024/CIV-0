#include "State.h"

State::State(int buildTime)
{
    this->gameLoopCounter = 0;
    this->buildTime = buildTime;
}


State::~State() {}

int State::getGameLoopCounter()
{
    return gameLoopCounter;
}

int State::getBuildTime()
{
    return buildTime;
}

void State::incrementGameLoopCounter()
{
    gameLoopCounter++;
}