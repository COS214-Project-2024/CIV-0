#ifndef SHOPPINGMALL_H
#define SHOPPINGMALL_H

#include "EconomicBuilding.h"

class ShoppingMall : public EconomicBuilding
{
public:
    ShoppingMall();
    ShoppingMall(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~ShoppingMall();

    void update();
    Entity* clone();
};

#endif // SHOPPINGMALL_H
