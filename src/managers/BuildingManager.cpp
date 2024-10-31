#include "BuildingManager.h"
#include "factory/building/ResidentialBuildingFactory.h"
#include "city/City.h"

BuildingManager::BuildingManager() {}
BuildingManager::~BuildingManager() {}

bool BuildingManager::buildBuilding(EntityType type, Size size, int x, int y)
{
    ResidentialBuildingFactory *aFactory = new ResidentialBuildingFactory();
    Entity *newResidential;

    switch (size)
    {
    case Size::SMALL:
        newResidential = aFactory->createSmallEntity(type, x, y);
        City::instance()->addEntity(newResidential);
        break;

    case Size::MEDIUM:
        newResidential = aFactory->createMediumEntity(type, x, y);
        City::instance()->addEntity(newResidential);
        break;

    case Size::LARGE:
        newResidential = aFactory->createLargeEntity(type, x, y);
        City::instance()->addEntity(newResidential);
        break;

    default:
        break;
    }

    delete aFactory;

    return true;
}