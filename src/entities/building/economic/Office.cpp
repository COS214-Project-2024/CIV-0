#include "Office.h"

Office::Office() {}
Office::~Office() {}

Office::Office(EntityConfig ec, Size size, int xPos, int yPos) : EconomicBuilding(ec, size, xPos, yPos)
{

}

void Office::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateOffice(this);
        }
    }
}

Entity* Office::clone()
{
    Entity* e = new Office(*ec, size, xPosition, yPosition);
    return e;
}
