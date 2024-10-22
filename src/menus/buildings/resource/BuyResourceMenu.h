#ifndef BUYRESOURCEMENU_H
#define BUYRESOURCEMENU_H

#include "menus/base/BuyMenu.h"

class BuyResourceMenu : public BuyMenu
{
public:
    BuyResourceMenu();
    ~BuyResourceMenu();

protected:
    EntityType chooseEntityType() override; // Override to choose resource building types
};

#endif // BUYRESOURCEMENU_H
