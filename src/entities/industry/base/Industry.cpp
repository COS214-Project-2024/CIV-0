#include "Industry.h"

Industry::Industry() : Entity() {}
Industry::~Industry() {}

Industry::Industry(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
    cost = ec.cost;
    subscribeToAllResidentialInRadius();
}

Industry::Industry(Industry *industry) : Entity(industry)
{
    this->output = industry->output;
    this->cost = industry->cost;
    subscribeToAllResidentialInRadius();
}

int Industry::getLevel()
{
    return 0;
}

int Industry::getOutput()
{
    return output;
}

void Industry::setOutput(int output)
{
    this->output = output;
}

Cost Industry::getCost() {
    return cost;
}