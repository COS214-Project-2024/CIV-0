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
#include "menus/road/BuyRoadMenu.h"
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
     * @brief Sets the current menu to display using a dynamic menu.
     * @param menu The shared pointer to the menu to set as current.
     */
    void setCurrentMenu(std::shared_ptr<IMenu> menu);

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
    void setCity(City *city);

    /**
     * @brief Gets the reference to the City object.
     * @return Pointer to the City object.
     */
    City *getCity() const;

    /**
     * @brief Clears the terminal screen.
     */
    void clearScreen() const;

private:
    /**
     * @brief Private constructor for enforcing the Singleton pattern.
     */
    MenuManager();

    /**
     * @brief Destructor for MenuManager.
     */
    ~MenuManager();

    std::shared_ptr<IMenu> currentMenu; ///< Pointer to the currently active menu.
    City *city = nullptr;               ///< Pointer to the City object.

    std::unordered_map<Menu, std::shared_ptr<IMenu>> menus; ///< Map of menus with the Menu enum as keys.

    /**
     * @brief Deleted copy constructor to enforce singleton pattern.
     */
    MenuManager(const MenuManager &) = delete;

    /**
     * @brief Deleted assignment operator to enforce singleton pattern.
     */
    MenuManager &operator=(const MenuManager &) = delete;
};

#endif // MENUMANAGER_H
