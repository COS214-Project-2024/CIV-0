#ifndef DISPLAYCITYMENU_H
#define DISPLAYCITYMENU_H

#include "menus/base/IMenu.h"

class DisplayCityMenu : public IMenu
{
public:
    DisplayCityMenu();
    ~DisplayCityMenu();

    /**
     * @brief Displays the "Display City" menu.
     */
    void display() const override;

    /**
     * @brief Handles user input in the "Display City" menu.
     */
    void handleInput() override;

    void displayCity() const;
};

#endif // DISPLAYCITYMENU_H
