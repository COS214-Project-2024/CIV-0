#include "ShoppingMall.h"

ShoppingMall::ShoppingMall() {}
ShoppingMall::~ShoppingMall() {}

ShoppingMall::ShoppingMall(EntityConfig ec, Size size, int xPos, int yPos) : EconomicBuilding(ec, size, xPos, yPos)
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
    Entity* e = new ShoppingMall(*ec, size, xPosition, yPosition);
    return e;
}
