#include "Built.h"

Built::Built(int buildTime) : State(buildTime) {}
Built::Built(Built* built) : State(built) {}
Built::~Built() {}

State* Built::update()
{
    return this;
}

State* Built::clone()
{
    return new Built(this);
}