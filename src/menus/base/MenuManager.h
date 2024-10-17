#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "IMenu.h"
#include "city/City.h"
#include "utils/Menu.h"
#include "menus/main/MainMenu.h"
#include "menus/policy/PolicyMenu.h"
#include "menus/upgrades/UpgradesMenu.h"
#include "menus/tax/TaxMenu.h"
#include "menus/buildings/BuildingsMenu.h"
#include <memory>
#include <unordered_map>
#include <string>

/**
 * @brief Manages different menus and allows switching between them.
 * Implements the Singleton design pattern.
 */
class MenuManager
{
public:
    /**
     * @brief Provides access to the single instance of MenuManager.
     * @return The singleton instance of MenuManager.
     */
    static MenuManager &instance();

    /**
     * @brief Sets the current menu to display, based on the provided menu type.
     * @param menuType The type of the menu to switch to, defined by an enum.
     */
    void setCurrentMenu(Menu menuType);

    /**
     * @brief Displays the currently active menu.
     */
    void displayCurrentMenu();

    /**
     * @brief Handles user input for the currently active menu.
     */
    void handleCurrentMenuInput();

    /**
     * @brief Sets the reference to the City object to be used by menus.
     * @param city Pointer to the City object.
     */
    void setCity(City *city) { this->city = city; }

    /**
     * @brief Gets the reference to the City object.
     * @return Pointer to the City object.
     */
    City *getCity() const { return city; }

    /**
     * @brief Clears the terminal screen.
     */
    void clearScreen() const { system("clear"); }

private:
    /**
     * @brief Private constructor for enforcing the Singleton pattern.
     */
    MenuManager();

    /**
     * @brief Destructor for MenuManager.
     */
    ~MenuManager();

    std::shared_ptr<IMenu> currentMenu; ///< Pointer to the currently active menu
    City *city = nullptr;               ///< Pointer to the City object

    std::unordered_map<Menu, std::shared_ptr<IMenu>> menus; ///< Map of menus with the Menu enum as keys

    // Delete copy constructor and assignment operator to enforce singleton pattern
    MenuManager(const MenuManager &) = delete;
    MenuManager &operator=(const MenuManager &) = delete;
};

#endif // MENUMANAGER_H
