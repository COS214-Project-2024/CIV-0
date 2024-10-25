#include "Apartment.h"

Apartment::Apartment() {}
Apartment::~Apartment() {}

Apartment::Apartment(EntityConfig ec, Size size, int xPos, int yPos) : ResidentialBuilding(ec, size, xPos, yPos)
{

}

Entity* Apartment::clone()
{
    Entity* e = new Apartment(*ec, size, xPosition, yPosition);
    return e;
}