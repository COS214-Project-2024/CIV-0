#include "AmenityManager.h"
#include "city/City.h"
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
void AmenityManager::buildAmenity(EntityType type, Size size, int xPos, int yPos)
{
    AmenityFactory *aFactory = new AmenityFactory();
    Entity *newAmenity;

    switch (size)
    {
    case Size::SMALL:
        newAmenity = aFactory->createSmallEntity(type, xPos, yPos);
        City::instance()->addEntity(newAmenity);
        break;

    case Size::MEDIUM:
        newAmenity = aFactory->createMediumEntity(type, xPos, yPos);
        City::instance()->addEntity(newAmenity);
        break;

    case Size::LARGE:
        newAmenity = aFactory->createLargeEntity(type, xPos, yPos);
        City::instance()->addEntity(newAmenity);
        break;

    default:
        break;
    }

    delete aFactory;
}
