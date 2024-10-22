#ifndef BUYUTILITYMENU_H
#define BUYUTILITYMENU_H

#include "menus/base/BuyMenu.h"

class BuyUtilityMenu : public BuyMenu
{
public:
    BuyUtilityMenu();
    ~BuyUtilityMenu();

protected:
    EntityType chooseEntityType() override; // Override to choose utility building types
};

#endif // BUYUTILITYMENU_H
