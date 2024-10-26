#include "Industry.h"

Industry::Industry() : Entity() {}
Industry::~Industry() {}

Industry::Industry(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
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

Industry::Industry(Industry* industry) : Entity(industry) {
    this->output = industry->output;
    subscribeToAllResidentialInRadius();
}
