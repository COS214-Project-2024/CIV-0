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

    /**
     * @brief Displays the entire city grid without filtering.
     */
    void displayCity() const;

    /**
     * @brief Displays only entities of a specified type in the city grid.
     *
     * @tparam T The type of entity to display (e.g., ResidentialBuilding).
     */
    template <typename T>
    void displayCityByType() const;
};

#endif // DISPLAYCITYMENU_H
