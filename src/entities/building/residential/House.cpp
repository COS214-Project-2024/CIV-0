#include "House.h"

House::House() {}
House::~House() {}

House::House(House* entity) : ResidentialBuilding(entity)
{

}

House::House(EntityConfig ec, Size size, int xPos, int yPos) : ResidentialBuilding(ec, size, xPos, yPos)
{

    switch(size)
    {
        case(Size::SMALL):
            setCapacity(2);
            break;
        case(Size::MEDIUM):
            setCapacity(5);
            break;
        case(Size::LARGE):
            setCapacity(8);
            break;
        default:
            setCapacity(0);
            break;
    }
}

Entity* House::clone()
{
    return new House(this);
}
