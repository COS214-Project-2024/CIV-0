#include "ShoppingMall.h"

ShoppingMall::ShoppingMall() {}
ShoppingMall::~ShoppingMall() {}

ShoppingMall::ShoppingMall(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : EconomicBuilding(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{

}

void ShoppingMall::update()
{
    for(Observer* o : subscribers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateShoppingMall(this);
        }
    }
}

Entity* ShoppingMall::clone()
{
    Entity* e = new ShoppingMall(electricityConsumption, waterConsumption, symbol, effectRadius, localEffectStrength, globalEffectStrength, width, height, revenue, size, xPosition, yPosition, state->getBuildTime());
    return e;
}
