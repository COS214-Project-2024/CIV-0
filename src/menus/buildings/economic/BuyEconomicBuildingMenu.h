#ifndef BUYECONOMICBUILDINGMENU_H
#define BUYECONOMICBUILDINGMENU_H

#include "menus/base/BuyMenu.h"

class BuyEconomicBuildingMenu : public BuyMenu
{
public:
    BuyEconomicBuildingMenu();
    ~BuyEconomicBuildingMenu();

protected:
    EntityType chooseEntityType() override; // Override to choose economic building types
};

#endif // BUYECONOMICBUILDINGMENU_H
