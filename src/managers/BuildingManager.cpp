#include "BuildingManager.h"
#include "factory/building/ResidentialBuildingFactory.h"
#include "factory/building/EconomicBuildingFactory.h"
#include "city/City.h"

BuildingManager::BuildingManager() {}
BuildingManager::~BuildingManager() {}

bool BuildingManager::buildBuilding(EntityType type, Size size, int x, int y)
{
    Entity *newBuilding;

    if (type == EntityType::HOUSE || type == EntityType::APARTMENT)
    {
        ResidentialBuildingFactory *aFactory = new ResidentialBuildingFactory();
        switch (size)
        {
        case Size::SMALL:
            newBuilding = aFactory->createSmallEntity(type, x, y);
            City::instance()->addEntity(newBuilding);
            break;

        case Size::MEDIUM:
            newBuilding = aFactory->createMediumEntity(type, x, y);
            City::instance()->addEntity(newBuilding);
            break;

        case Size::LARGE:
            newBuilding = aFactory->createLargeEntity(type, x, y);
            City::instance()->addEntity(newBuilding);
            break;

        default:
            break;
        }
        delete aFactory;
    }
    else if (type == EntityType::FACTORY || type == EntityType::SHOPPINGMALL || type == EntityType::OFFICE)
    {
        EconomicBuildingFactory *eFactory = new EconomicBuildingFactory();
        switch (size)
        {
        case Size::SMALL:
            newBuilding = eFactory->createSmallEntity(type, x, y);
            City::instance()->addEntity(newBuilding);
            break;

        case Size::MEDIUM:
            newBuilding = eFactory->createMediumEntity(type, x, y);
            City::instance()->addEntity(newBuilding);
            break;

        case Size::LARGE:
            newBuilding = eFactory->createLargeEntity(type, x, y);
            City::instance()->addEntity(newBuilding);
            break;

        default:
            break;
        }
        delete eFactory;
    }
    else
    {
        return false;
    }
    return true;
}