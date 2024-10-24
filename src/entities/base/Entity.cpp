#include "Entity.h"
#include "entities/state/UnderConstruction.h"
#include "entities/state/Built.h"

Entity::Entity()
{

}

Entity::Entity(Entity* entity)
{
    this->electricityConsumption = entity->electricityConsumption;
    this->waterConsumption = entity->waterConsumption;
    this->symbol = entity->symbol;
    this->effectRadius = entity->effectRadius;
    this->localEffectStrength = entity->localEffectStrength;
    this->globalEffectStrength = entity->globalEffectStrength;
    this->width = entity->width;
    this->height = entity->height;
    this->revenue = entity->revenue;
    this->size = entity->size;
    this->xPosition = entity->xPosition;
    this->yPosition = entity->yPosition;
    this->ec = entity->ec;
    if(!entity->isBuilt())
    {
        state = new UnderConstruction(3);
    }
    else
    {
        state = new Built(3);
    }
}

Entity::Entity(EntityConfig ec, Size size, int xPos, int yPos)
{
    this->electricityConsumption = ec.electricityConsumption;
    this->waterConsumption = ec.waterConsumption;
    this->symbol = ec.symbol;
    this->effectRadius = ec.effectRadius;
    this->localEffectStrength = ec.localEffectStrength;
    this->globalEffectStrength = ec.globalEffectStrength;
    this->width = ec.width;
    this->height = ec.height;
    this->revenue = ec.revenue;
    this->size = size;
    this->xPosition = xPos;
    this->yPosition = yPos;
    this->ec = &ec;
    if(ec.buildTime!=0)
    {
        state = new UnderConstruction(ec.buildTime);
    }
    else
    {
        state = new Built(ec.buildTime);
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
