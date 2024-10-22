#include "Utility.h"

Utility::Utility() {}
Utility::~Utility() {}

Utility::Utility(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
}

int Utility::getOutput()
{
    return output;
}

void Utility::setOutput(int output)
{
    this->output = output;
}