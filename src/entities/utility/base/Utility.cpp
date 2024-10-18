#include "Utility.h"

Utility::Utility(int output, int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Entity(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime) {
    this->output = output;
}

Utility::Utility(Utility* utility) : Entity(utility) {
    this->output = utility->output;
}

Utility::~Utility() {

}

int Utility::getOutput() {
    return output;
}

void Utility::setOutput(int output) {
    this->output = output;
}