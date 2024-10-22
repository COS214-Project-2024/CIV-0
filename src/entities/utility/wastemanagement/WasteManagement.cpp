#include "WasteManagement.h"

WasteManagement::WasteManagement() {}
WasteManagement::~WasteManagement() {}

WasteManagement::WasteManagement(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(20); //TODO - change value
}

void WasteManagement::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateUtility(this);
        }
    }
}

Entity* WasteManagement::clone()
{
    Entity* e = new WasteManagement(*ec, size, xPosition, yPosition);
    return e;
}