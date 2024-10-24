#include "School.h"

School::School() {}
School::~School() {}

School::School(EntityConfig ec, Size size, int xPos, int yPos) : ServiceBuilding(ec, size, xPos, yPos)
{

}

void School::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateSchool(this);
        }
    }
}

Entity* School::clone()
{
    Entity* e = new School(*ec, size, xPosition, yPosition);
    return e;
}
