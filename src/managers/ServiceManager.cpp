#include "ServiceManager.h"
#include "city/City.h"
/**
 * @brief Construct a new Service Manager:: Service Manager object
 *
 */
ServiceManager::ServiceManager() {}

/**
 * @brief Destroy the Service Manager:: Service Manager object
 *
 */
ServiceManager::~ServiceManager() {}

/**
 * @brief Returns Service building
 *
 * @param type
 * @param size
 * @param xPos
 * @param yPos
 * @return ServiceBuilding*
 */
void ServiceManager::buildService(EntityType type, Size size, int xPos, int yPos)
{
    ServiceBuildingFactory *sb = new ServiceBuildingFactory();
    Entity *newService;

    switch (size)
    {
    case Size::SMALL:
        newService = sb->createSmallEntity(type, xPos, yPos);
        City::instance()->addEntity(newService);
        break;

    case Size::MEDIUM:
        newService = sb->createMediumEntity(type, xPos, yPos);
        City::instance()->addEntity(newService);
        break;

    case Size::LARGE:
        newService = sb->createLargeEntity(type, xPos, yPos);
        City::instance()->addEntity(newService);
        break;

    default:
        break;
    }

    delete sb;
}