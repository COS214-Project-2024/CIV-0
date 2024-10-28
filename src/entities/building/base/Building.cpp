#include "Building.h"

Building::Building() {}
Building::~Building() {}

Building::Building(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{

}

Building::Building(Building* building) : Entity(building)
{

}