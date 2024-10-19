#ifndef ROAD_H
#define ROAD_H

#include "entities/base/Entity.h"

class Road : public Entity
{
public:
    Road(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    ~Road();
    void update();
    Entity* clone();
};

#endif // ROAD_H
