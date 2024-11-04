#include "Office.h"

Office::~Office() {}

Office::Office(EntityConfig ec, Size size, int xPos, int yPos) : EconomicBuilding(ec, size, xPos, yPos)
{

}

Office::Office(Office* office) : EconomicBuilding(office)
{
    
}

void Office::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateOffice(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt()) {
        updateBuildState();
    }
}

Entity* Office::clone()
{
    return new Office(this);
}
