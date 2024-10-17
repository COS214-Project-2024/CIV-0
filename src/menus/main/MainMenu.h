#ifndef MAINMENU_H
#define MAINMENU_H

#include "menus/base/IMenu.h"

class MainMenu : public IMenu
{
public:
    MainMenu();
    ~MainMenu();

    void display() const override;
    void handleInput() const override;
};

#endif // MAINMENU_H
