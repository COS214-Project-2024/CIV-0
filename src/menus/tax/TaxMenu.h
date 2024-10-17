#ifndef TAXMENU_H
#define TAXMENU_H

#include "menus/base/IMenu.h"

class TaxMenu : public IMenu
{
public:
    TaxMenu();
    ~TaxMenu();

    void display() const override;
    void handleInput() const override;
};

#endif // TAXMENU_H
