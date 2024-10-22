#include "Road.h"

Road::Road(EntityConfig ec, Size size, int xPos, int yPos) : Entity(ec, size, xPos, yPos)
{

}
Road::~Road() {}

void Road::update()
{
    //Does nothing
}

Entity* Road::clone()
{
    Entity* e = new Road(*ec, size, xPosition, yPosition);
    return e;
}
