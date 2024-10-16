#include "Entity.h"
#include "entities/state/UnderCOnstruction.h"
#include "entities/state/Built.h"

Entity::Entity()
{

}

Entity::Entity(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime)
{
    this->electricityConsumption = electricity;
    this->waterConsumption = water;
    this->symbol = symbol;
    this->effectRadius = radius;
    this->localEffectStrength = localEffect;
    this->globalEffectStrength = globalEffect;
    this->width = width;
    this->height = height;
    this->revenue = revenue;
    this->size = size;
    this->xPosition = xPos;
    this->yPosition = yPos;
    state = new UnderConstruction(buildTime);

    State* newState = state->initialize();
    if (newState != state)
    {
        delete state;
        state = newState;
    }
}

Entity::~Entity()
{
    delete state;
}

/*
Returns true if entity is within the effect Radius
NOTE - If the Entity is on the Border of the radius - it does not count (returns false)
*/
bool Entity::isWithinEffectRadius(Entity* entity)
{
    if(entity->getXPosition() + entity->getWidth()<=xPosition-effectRadius || entity->getXPosition()>=xPosition+width+effectRadius)
    {
        return false;
    }
    if(entity->getYPosition() + entity->getHeight()<=yPosition-effectRadius || entity->getYPosition()>=yPosition+height+effectRadius)
    {
        return false;
    }
    return true;
}

int Entity::getXPosition()
{
    return xPosition;
}

int Entity::getYPosition()
{
    return yPosition;
}

void Entity::setXPosition(int x)
{
    xPosition = x;
}

void Entity::setYPosition(int y)
{
    yPosition = y;
}

int Entity::getRevenue()
{
    return revenue;
}

int Entity::getWidth()
{
    return width;
}

int Entity::getHeight()
{
    return height;
}

bool Entity::isBuilt()
{
    return dynamic_cast<Built*>(state) != nullptr;
}

void Entity::updateBuildState()
{
    State* newState = state->update();
    if (newState != state)
    {
        delete state;
        state = newState;
    }
}