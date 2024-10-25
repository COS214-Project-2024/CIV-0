#ifndef ROAD_H
#define ROAD_H

#include "entities/base/Entity.h"

class Road : public Entity
{
public:
    Road(EntityConfig ec, Size size, int xPos, int yPos);
    Road(Road* road);
    ~Road();
    void update();
    Entity* clone() override;
};

#endif // ROAD_H
