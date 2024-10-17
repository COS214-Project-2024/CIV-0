#ifndef UPGRADESMENU_H
#define UPGRADESMENU_H

#include "menus/base/IMenu.h"

class UpgradesMenu : public IMenu
{
public:
    UpgradesMenu();
    ~UpgradesMenu();

    void display() const override;
    void handleInput() const override;
};

#endif // UPGRADESMENU_H
