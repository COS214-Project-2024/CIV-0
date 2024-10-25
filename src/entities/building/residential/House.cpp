#include "House.h"

House::House() {}
House::~House() {}

House::House(EntityConfig ec, Size size, int xPos, int yPos) : ResidentialBuilding(ec, size, xPos, yPos)
{

}

Entity* House::clone()
{
    Entity* e = new House(*ec, size, xPosition, yPosition);
    return e;
}
