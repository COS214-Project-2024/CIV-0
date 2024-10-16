#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "utils/Size.h"
#include "entities/state/State.h"

// Forward declarations
class UnderConstruction; 
class Built; 

class Entity
{
private:
    std::string symbol;
    int effectRadius;
    int localEffectStrength;
    int globalEffectStrength;
    int width;
    int height;
    int xPosition; //Bottom left corner
    int yPosition; //Bottom left corner
    Size size;
    State* state;
    int revenue;
    float electricityConsumption;
    float waterConsumption;
public:
    Entity();
    Entity(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~Entity();
    virtual void update(){}; //!Needs to be pure
    bool isWithinEffectRadius(Entity* entity);
    int getXPosition();
    int getYPosition();
    void setXPosition(int x);
    void setYPosition(int y);
    virtual Entity* clone(){return nullptr;};//!Needs to be pure
    int getRevenue();
    int getWidth();
    int getHeight();
    bool isBuilt();
    void updateBuildState();
};

#endif // ENTITY_H
