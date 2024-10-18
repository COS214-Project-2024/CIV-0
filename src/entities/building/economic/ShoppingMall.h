#ifndef SHOPPINGMALL_H
#define SHOPPINGMALL_H

#include "EconomicBuilding.h"

class ShoppingMall : public EconomicBuilding
{
public:
    ShoppingMall();
    ShoppingMall(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~ShoppingMall();

    void update();
    Entity* clone();
};

#endif // SHOPPINGMALL_H
