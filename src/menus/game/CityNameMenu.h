#ifndef CITYNAMEMENU_H
#define CITYNAMEMENU_H

#include "menus/base/IMenu.h"

/**
 * @class CityNameMenu
 * @brief Menu for entering the city name.
 */
class CityNameMenu : public IMenu
{
public:
    /**
     * @brief Constructor for CityNameMenu.
     */
    CityNameMenu();

    /**
     * @brief Destructor for CityNameMenu.
     */
    ~CityNameMenu();

    /**
     * @brief Displays the menu to the user.
     */
    void display() const override;

    /**
     * @brief Handles user input for the menu.
     */
    void handleInput() override;
};

#endif // CITYNAMEMENU_H
