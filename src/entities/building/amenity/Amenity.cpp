#include "Amenity.h"

Amenity::~Amenity() {}

Amenity::Amenity(EntityConfig ec, Size size, int xPos, int yPos) : Building(ec, size, xPos, yPos)
{
    subscribeToAllResidentialInRadius();
}

Amenity::Amenity(Amenity* amenity) : Building(amenity)
{
    subscribeToAllResidentialInRadius();
}