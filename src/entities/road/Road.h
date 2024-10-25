#ifndef ROAD_H
#define ROAD_H

#include "entities/base/Entity.h"

class Road : public Entity
{
public:
    Road(EntityConfig ec, Size size, int xPos, int yPos);
    ~Road();
    void update();
    Entity* clone();
};

#endif // ROAD_H
