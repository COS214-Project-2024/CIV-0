#include "Industry.h"

Industry::Industry() {}
Industry::~Industry() {}

Industry::Industry(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
}

int Industry::getOutput()
{
    return output;
}

void Industry::setOutput(int output)
{
    this->output = output;
}