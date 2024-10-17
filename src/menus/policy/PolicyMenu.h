#ifndef POLICYMENU_H
#define POLICYMENU_H

#include "menus/base/IMenu.h"

class PolicyMenu : public IMenu
{
public:
    PolicyMenu();
    ~PolicyMenu();

    void display() const override;
    void handleInput() const override;
};

#endif // POLICYMENU_H
