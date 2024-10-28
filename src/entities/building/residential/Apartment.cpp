#include "Apartment.h"

Apartment::Apartment() {}
Apartment::~Apartment() {}

Apartment::Apartment(Apartment* apartment) : ResidentialBuilding(apartment)
{

}

Apartment::Apartment(EntityConfig ec, Size size, int xPos, int yPos) : ResidentialBuilding(ec, size, xPos, yPos)
{
    switch(size)
    {
        case(Size::SMALL):
            setCapacity(60);
            break;
        case(Size::MEDIUM):
            setCapacity(100);
            break;
        case(Size::LARGE):
            setCapacity(300);
            break;
        default:
            setCapacity(0);
            break;
    }
}

Entity* Apartment::clone()
{
    return new Apartment(this);
}