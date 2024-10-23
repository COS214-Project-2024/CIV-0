#include "ResidentialBuildingFactory.h"

ResidentialBuildingFactory::ResidentialBuildingFactory() {

}
ResidentialBuildingFactory::~ResidentialBuildingFactory() {
    
}

Entity* ResidentialBuildingFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	return nullptr;
}

Entity* ResidentialBuildingFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	return nullptr;
}

Entity * ResidentialBuildingFactory::createLargeEntity(EntityType type, int xPos, int yPos)
{
return nullptr;
}

Entity * ResidentialBuildingFactory::createHouse(Size size, int xPos, int yPos)
{
return nullptr;
}

Entity * ResidentialBuildingFactory::createApartment(Size size, int xPos, int yPos)
{
return nullptr;
}
