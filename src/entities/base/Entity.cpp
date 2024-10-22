#include "Entity.h"
#include "entities/state/UnderConstruction.h"
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
    if(buildTime!=0)
    {
        state = new UnderConstruction(buildTime);
    }
    else
    {
        state = new Built(buildTime);
    }
}

Entity::~Entity()
{
    if(state != nullptr)
    {
        delete state;
        state = nullptr;
    }
}

//Note: If the entity is on the border of the radius, it does not count (returns false).
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

void Entity::setSymbol(std::string symbol)
{
    this->symbol = symbol;
}
