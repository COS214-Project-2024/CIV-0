#include "AmenityManager.h"

#include <iostream>

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

void AmenityManager::buildAmenity(EntityType type, Size size, int xPos, int yPos) {
	AmenityFactory *aFactory = new AmenityFactory();
	Entity *newAmenity;

	newAmenity = aFactory->createEntity(type, size, xPos, yPos);
	City::instance()->addEntity(newAmenity);

	delete aFactory;
}
