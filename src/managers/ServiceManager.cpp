#include "ServiceManager.h"
/**
 * @brief Construct a new Service Manager:: Service Manager object
 * 
 */
ServiceManager::ServiceManager(){}

/**
 * @brief Destroy the Service Manager:: Service Manager object
 * 
 */
ServiceManager::~ServiceManager(){}

/**
 * @brief Returns Service building
 * 
 * @param type 
 * @param size 
 * @param xPos 
 * @param yPos 
 * @return ServiceBuilding* 
 */
ServiceBuilding* ServiceManager::buildService(EntityType type, Size size, int xPos, int yPos){
    ServiceBuildingFactory* sb = new ServiceBuildingFactory();

switch (size)
    {
    case Size::SMALL:
            return dynamic_cast<ServiceBuilding*>(sb->createSmallEntity(type,xPos,yPos));
        break;

    case Size::MEDIUM:
            return dynamic_cast<ServiceBuilding*>(sb->createMediumEntity(type,xPos,yPos));
        break;

    case Size::LARGE:
            return dynamic_cast<ServiceBuilding*>(sb->createLargeEntity(type,xPos,yPos));
        break;
    
    default:
            return NULL;
        break;
    }

    delete sb;

}