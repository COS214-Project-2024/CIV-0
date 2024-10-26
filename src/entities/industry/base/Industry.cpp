#include "Industry.h"

Industry::Industry() {}
Industry::~Industry() {}

Industry::Industry(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
    subscribeToAllResidentialInRadius();
}

Industry::Industry(Industry* industry): Entity(industry)
{
    subscribeToAllResidentialInRadius();
}

int Industry::getOutput()
{
    return output;
}

void Industry::setOutput(int output)
{
    this->output = output;
}