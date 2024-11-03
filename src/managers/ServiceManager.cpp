#include "ServiceManager.h"
#include "city/City.h"

ServiceManager::ServiceManager() {}

ServiceManager::~ServiceManager() {}

bool ServiceManager::buildService(EntityType type, Size size, int xPos, int yPos){
    ServiceBuildingFactory sb;

    if (type == EntityType::POLICESTATION || type == EntityType::HOSPITAL || type == EntityType::SCHOOL) {
        ServiceBuildingFactory *sb = new ServiceBuildingFactory();
        Entity *newServiceBuilding = sb->createEntity(type, size, xPos, yPos);
        City::instance()->addEntity(newServiceBuilding);
        delete sb;
        return true;
    }

    return false;
}