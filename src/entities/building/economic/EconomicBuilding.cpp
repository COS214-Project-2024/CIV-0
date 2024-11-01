#include "EconomicBuilding.h"

EconomicBuilding::~EconomicBuilding() {}

EconomicBuilding::EconomicBuilding(EntityConfig ec, Size size, int xPos, int yPos) : Building(ec, size, xPos, yPos)
{
    subscribeToAllResidentialInRadius();
}

EconomicBuilding::EconomicBuilding(EconomicBuilding* economic) : Building(economic)
{
    subscribeToAllResidentialInRadius();
}
