#include "AmenityManager.h"
#include "city/City.h"

AmenityManager::AmenityManager() {}

AmenityManager::~AmenityManager() {}

void AmenityManager::buildAmenity(EntityType type, Size size, int xPos, int yPos) {
	AmenityFactory *aFactory = new AmenityFactory();
	Entity *newAmenity;

	newAmenity = aFactory->createEntity(type, size, xPos, yPos);
	City::instance()->addEntity(newAmenity);

	delete aFactory;
}
