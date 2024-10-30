#include "Utility.h"

Utility::Utility(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{
    output = 0;
    cost = ec.cost;
    subscribeToAllResidentialInRadius();
}

Utility::Utility() : Entity() {
    
}

Utility::Utility(Utility* utility) : Entity(utility) {
    this->output = utility->output;
    subscribeToAllResidentialInRadius();
}

Utility::~Utility() {

}

int Utility::getOutput() {
    return output;
}

void Utility::setOutput(int output) {
    this->output = output;
}

Cost Utility::getCost() {
    return cost;
}