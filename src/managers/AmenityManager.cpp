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
Amenity* AmenityManager::buildAmenity(EntityType type, Size size, int xPos, int yPos){
    AmenityFactory* aFactory = new AmenityFactory();

    switch (size)
    {
    case Size::SMALL:
            return dynamic_cast<Amenity*>(aFactory->createSmallEntity(type,xPos,yPos));
        break;

    case Size::MEDIUM:
            return dynamic_cast<Amenity*>(aFactory->createMediumEntity(type,xPos,yPos));
        break;

    case Size::LARGE:
            return dynamic_cast<Amenity*>(aFactory->createLargeEntity(type,xPos,yPos));
        break;
    
    default:
            return NULL;
        break;
    }


    delete aFactory;
}
