#ifndef BUYAMENITYMENU_H
#define BUYAMENITYMENU_H

#include "menus/base/BuyMenu.h"

class BuyAmenityMenu : public BuyMenu
{
protected:
    EntityType chooseEntityType() override;
};

#endif // BUYAMENITYMENU_H
