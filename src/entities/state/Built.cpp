#include "Built.h"

Built::Built(int buildTime) : State(buildTime) {}
Built::~Built() {}

State* Built::update()
{
    return this;
}

State* Built::initialize()
{
    return this;
}