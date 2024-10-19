#include "Amenity.h"

Amenity::Amenity() {}
Amenity::~Amenity() {}

Amenity::Amenity(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Building(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}
