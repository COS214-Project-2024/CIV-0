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

void ServiceManager::buildService(EntityType type, Size size, int xPos, int yPos){
    ServiceBuildingFactory sb;
    if(size == Size::SMALL){
        if(type == EntityType::POLICESTATION){
            City* c = City::instance();
            c->addEntity(sb.createSmallEntity(type,xPos,yPos));
            return;
        }
        if(type == EntityType::HOSPITAL){
            City* c = City::instance();
            c->addEntity(sb.createSmallEntity(type,xPos,yPos));
            return;
        }
        if(type == EntityType::SCHOOL){
            City* c = City::instance();
            c->addEntity(sb.createSmallEntity(type,xPos,yPos));
            return;
        }
    }//small

    if(size == Size::MEDIUM){
        if(type == EntityType::POLICESTATION){
            City* c = City::instance();
            c->addEntity(sb.createMediumEntity(type,xPos,yPos));
            return;
        }
        if(type == EntityType::HOSPITAL){
            City* c = City::instance();
            c->addEntity(sb.createMediumEntity(type,xPos,yPos));
            return;
        }
        if(type == EntityType::SCHOOL){
            City* c = City::instance();
            c->addEntity(sb.createMediumEntity(type,xPos,yPos));
            return;
        }
    }//medium

    if(size == Size::LARGE){
        if(type == EntityType::POLICESTATION){
            City* c = City::instance();
            c->addEntity(sb.createLargeEntity(type,xPos,yPos));
            return;
        }
        if(type == EntityType::HOSPITAL){
            City* c = City::instance();
            c->addEntity(sb.createLargeEntity(type,xPos,yPos));
            return;
        }
        if(type == EntityType::SCHOOL){
            City* c = City::instance();
            c->addEntity(sb.createLargeEntity(type,xPos,yPos));
            return;
        }
    }//large
}