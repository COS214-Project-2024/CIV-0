#ifndef MAINMENU_H
#define MAINMENU_H

#include "IMenu.h"

class MainMenu : public IMenu
{
public:
    MainMenu();
    ~MainMenu();

    void display() const override;
    void handleInput() override;
};

#endif // MAINMENU_H
