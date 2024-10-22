#ifndef BUYTRANSPORTMENU_H
#define BUYTRANSPORTMENU_H

#include "menus/base/BuyMenu.h"

class BuyTransportMenu : public BuyMenu
{
public:
    BuyTransportMenu();
    ~BuyTransportMenu();

protected:
    EntityType chooseEntityType() override; // Override to choose transport building types
};

#endif // BUYTRANSPORTMENU_H
