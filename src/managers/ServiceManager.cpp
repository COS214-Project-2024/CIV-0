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

bool ServiceManager::buildService(EntityType type, Size size, int xPos, int yPos){
    ServiceBuildingFactory sb;
    if (type == EntityType::POLICESTATION || type == EntityType::HOSPITAL || type == EntityType::SCHOOL) {
        ServiceBuildingFactory * sb = new ServiceBuildingFactory();
        Entity *newServiceBuilding = sb->createEntity(type, size, xPos, yPos);
        City::instance()->addEntity(newServiceBuilding);
        delete sb;
        return true;
    }
    return false;
    
}