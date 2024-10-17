#ifndef BUILDINGSMENU_H
#define BUILDINGSMENU_H

#include "menus/base/IMenu.h"

class BuildingsMenu : public IMenu
{
public:
    BuildingsMenu();
    ~BuildingsMenu();

    void display() const override;
    void handleInput() const override;
};

#endif // BUILDINGSMENU_H
