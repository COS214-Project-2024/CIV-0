#include "ServiceBuilding.h"

ServiceBuilding::ServiceBuilding() {}
ServiceBuilding::~ServiceBuilding() {}

ServiceBuilding::ServiceBuilding(EntityConfig ec, Size size, int xPos, int yPos) : Building(ec, size, xPos, yPos)
{
    subscribeToAllResidentialInRadius();
}

ServiceBuilding::ServiceBuilding(ServiceBuilding* service) : Building(service)
{
    subscribeToAllResidentialInRadius();
}