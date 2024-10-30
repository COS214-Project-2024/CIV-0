#include "Entity.h"
#include "entities/state/UnderConstruction.h"
#include "entities/state/Built.h"
#include "city/City.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/road/Road.h"
#include <iostream>

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
    unsubscribeFromAllBuildings();
    if(state != nullptr)
    {
        delete state;
        state = nullptr;
    }
}

const std::vector<Entity*> Entity::getObservers()
{
    return observers;
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

void Entity::unsubscribe(Entity* subject)
{
    for(auto it = observers.begin(); it != observers.end(); it++)
    {
        if(*it == subject)
        {
            observers.erase(it);
            return;
        }
    }
}

void Entity::subscribe(Entity* entity)
{
    for(Entity* obs : observers)
    {
        if(obs == entity)
        {
            return;
        }
    }
    observers.push_back(entity);
}

void Entity::unsubscribeFromAllBuildings()
{
    for(Entity* e : observers)
    {
        e->unsubscribe(this);
        unsubscribe(e);
    }
}

//If you edit this you are signing your death warrent
void Entity::subscribeToAllResidentialInRadius()
{
    City* c = City::instance();

    for(int i = 0; i < c->getWidth(); i++)
    {
        for(int j = 0; j < c->getHeight(); j++)
        {
            if(dynamic_cast<ResidentialBuilding*>(c->getEntity(i, j)) != nullptr)
            {
                if(isWithinEffectRadius(c->getEntity(i, j)))
                {
                    subscribe(c->getEntity(i, j));
                    c->getEntity(i,j)->subscribe(this);
                }
            }
        }
    }
}

void Entity::residentialBuildingPlaced()
{
    City* c = City::instance();

    for(int i = 0; i < c->getWidth(); i++)
    {
        for(int j = 0; j < c->getHeight(); j++)
        {
             //Don't you dare touch this
            if(dynamic_cast<ResidentialBuilding*>(c->getEntity(i, j)) == nullptr && c->getEntity(i, j)!=nullptr && dynamic_cast<Road*>(c->getEntity(i, j)) == nullptr)
            {
                subscribeToAllResidentialInRadius();
            }
        }
    }
}

std::string Entity::getSymbol()
{
    return symbol;
}

float Entity::getElectricityConsumption()
{
    return electricityConsumption;
}

float Entity::getWaterConsumption()
{
    return waterConsumption;
}