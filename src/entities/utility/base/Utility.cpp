#include "Utility.h"

Utility::Utility(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
    cost = ec.cost;
    subscribeToAllResidentialInRadius();
}

Utility::Utility(Utility *utility) : Entity(utility)
{
    this->output = utility->output;
    this->cost = utility->cost;
    subscribeToAllResidentialInRadius();
}

Utility::~Utility()
{
}

int Utility::getLevel()
{
    return 0;
}

int Utility::getOutput()
{
    return output;
}

void Utility::setOutput(int output)
{
    this->output = output;
}

Cost Utility::getCost()
{
    return cost;
}