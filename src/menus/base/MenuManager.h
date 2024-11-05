/**
 * @file MenuManager.h
 * @brief Defines the MenuManager class for handling different game menus and switching between them.
 */

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
#include "menus/main/DisplayCityMenu.h"
#include "menus/buildings/amenity/BuyAmenityMenu.h"
#include "menus/buildings/economic/BuyEconomicBuildingMenu.h"
#include "menus/buildings/residential/BuyResidentialBuildingMenu.h"
#include "menus/buildings/transport/BuyTransportMenu.h"
#include "menus/buildings/utility/BuyUtilityMenu.h"
#include "menus/buildings/resource/BuyResourceMenu.h"
#include "menus/buildings/service/BuyServiceMenu.h"
#include "menus/buildings/demolish/DemolishMenu.h"
#include "menus/game/GameModeMenu.h"
#include "menus/game/CityNameMenu.h"
#include "menus/stats/StatsMenu.h"
#include "menus/road/BuyRoadMenu.h"
#include <memory>
#include <unordered_map>
#include <string>

/**
 * @class MenuManager
 * @brief Manages the different menus in the game and allows switching between them.
 *
 * MenuManager implements the Singleton design pattern, ensuring that only one instance of the class
 * exists and provides a global point of access to it.
 */
class MenuManager
{
public:
    /**
     * @brief Provides access to the single instance of MenuManager.
     *
     * Ensures that only one instance of MenuManager is created.
     * @return The singleton instance of MenuManager.
     */
    static MenuManager &instance();

    /**
     * @brief Sets the current menu to be displayed, using an enum value to select the menu.
     *
     * Changes the active menu based on the provided menu type, allowing seamless transitions between menus.
     * @param menuType The type of the menu to switch to, defined by the Menu enum.
     */
    void setCurrentMenu(Menu menuType);

    /**
     * @brief Sets the current menu using a dynamic menu object.
     *
     * Allows setting the current menu by passing a shared pointer to a custom menu object.
     * @param menu The shared pointer to the IMenu object to set as current.
     */
    void setCurrentMenu(std::shared_ptr<IMenu> menu);

    /**
     * @brief Displays the currently active menu.
     *
     * Calls the display method of the active menu to render its content to the terminal.
     */
    void displayCurrentMenu();

    /**
     * @brief Handles user input for the currently active menu.
     *
     * Delegates input handling to the active menu's handleInput method.
     */
    void handleCurrentMenuInput();

    /**
     * @brief Sets the City object reference for use in menus.
     *
     * Links the City object to the MenuManager, allowing menus to access and interact with city data.
     * @param city Pointer to the City object.
     */
    void setCity(City *city);

    /**
     * @brief Retrieves the City object reference.
     *
     * Provides access to the City object used by the MenuManager.
     * @return Pointer to the City object.
     */
    City *getCity() const;

    /**
     * @brief Clears the terminal screen.
     *
     * Utility method to clear the screen for cleaner menu displays.
     */
    void clearScreen() const;

private:
    /**
     * @brief Private constructor to enforce the Singleton pattern.
     *
     * Initializes all menus and stores them in a map with their corresponding enum keys.
     */
    MenuManager();

    /**
     * @brief Destructor for MenuManager.
     *
     * Cleans up resources and ensures proper destruction.
     */
    ~MenuManager();

    std::shared_ptr<IMenu> currentMenu; ///< Shared pointer to the currently active menu.
    City *city = nullptr;               ///< Pointer to the City object used by menus.

    std::unordered_map<Menu, std::shared_ptr<IMenu>> menus; ///< Map of available menus, indexed by the Menu enum.

    /**
     * @brief Deleted copy constructor to enforce Singleton pattern.
     *
     * Prevents copying of the MenuManager instance.
     */
    MenuManager(const MenuManager &) = delete;

    /**
     * @brief Deleted assignment operator to enforce Singleton pattern.
     *
     * Prevents assignment of the MenuManager instance.
     */
    MenuManager &operator=(const MenuManager &) = delete;
};

#endif // MENUMANAGER_H