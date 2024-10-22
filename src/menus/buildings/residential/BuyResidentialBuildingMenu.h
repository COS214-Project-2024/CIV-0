#ifndef BUYRESIDENTIALBUILDINGMENU_H
#define BUYRESIDENTIALBUILDINGMENU_H

#include "menus/base/BuyMenu.h"

class BuyResidentialBuildingMenu : public BuyMenu
{
public:
    BuyResidentialBuildingMenu();
    ~BuyResidentialBuildingMenu();

protected:
    EntityType chooseEntityType() override; // Override to choose residential building types
};

#endif // BUYRESIDENTIALBUILDINGMENU_H
