#include "WaterSupply.h"
#include "entities/utility/watersupply/WaterSupplyLevelOneUpgrade.h"

WaterSupply::~WaterSupply()
{
}

WaterSupply::WaterSupply(EntityConfig ec, Size size, int xPos, int yPos) : Utility(ec, size, xPos, yPos)
{
    setOutput(2000); // TODO - change value
}

WaterSupply::WaterSupply(WaterSupply *water) : Utility(water)
{
}

void WaterSupply::update()
{
    for (Entity *o : observers)
    {
        ResidentialBuilding *rb = dynamic_cast<ResidentialBuilding *>(o);

        if (rb)
        {
            rb->updateUtility(this);
        }
    }

    // This is for updating the build state (it should run once per game loop)
    if (!isBuilt())
    {
        updateBuildState();
    }
}

Entity *WaterSupply::clone()
{
    return new WaterSupply(this);
}

Entity *WaterSupply::upgrade()
{
    return new WaterSupplyLevelOneUpgrade(this);
}