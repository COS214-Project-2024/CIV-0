#include "AmenityManager.h"
/**
 * @brief Construct a new Amenity Manager:: Amenity Manager object
 * 
 */
AmenityManager::AmenityManager() {}

/**
 * @brief Destroy the Amenity Manager:: Amenity Manager object
 * 
 */
AmenityManager::~AmenityManager() {}

/**
 * @brief Construct a new Amenity
 * 
 * @param type 
 * @param size 
 * @param xPos 
 * @param yPos 
 */
void AmenityManager::buildAmenity(EntityType type, Size size, int xPos, int yPos){
    AmenityFactory aFactory;

    if(size == Size::SMALL){
        if(type == EntityType::PARK){
            City* c = City::instance();
            c->addEntity(aFactory.createSmallEntity(type,xPos,yPos));
            return;
        }

        if(type == EntityType::THEATER){
            City* c = City::instance();
            c->addEntity(aFactory.createSmallEntity(type,xPos,yPos));
            return;
        }

        if(type == EntityType::MONUMENT){
            City* c = City::instance();
            c->addEntity(aFactory.createSmallEntity(type,xPos,yPos));
            return;
        }
    }//small

    if(size == Size::MEDIUM){
        if(type == EntityType::PARK){
            City* c = City::instance();
            c->addEntity(aFactory.createMediumEntity(type,xPos,yPos));
            return;
        }

        if(type == EntityType::THEATER){
            City* c = City::instance();
            c->addEntity(aFactory.createMediumEntity(type,xPos,yPos));
            return;
        }

        if(type == EntityType::MONUMENT){
            City* c = City::instance();
            c->addEntity(aFactory.createMediumEntity(type,xPos,yPos));
            return;
        }
    }//medium

    if(size == Size::LARGE){
        if(type == EntityType::PARK){
            City* c = City::instance();
            c->addEntity(aFactory.createLargeEntity(type,xPos,yPos));
            return;
        }

        if(type == EntityType::THEATER){
            City* c = City::instance();
            c->addEntity(aFactory.createLargeEntity(type,xPos,yPos));
            return;
        }

        if(type == EntityType::MONUMENT){
            City* c = City::instance();
            c->addEntity(aFactory.createLargeEntity(type,xPos,yPos));
            return;
        }
    }//large
}
