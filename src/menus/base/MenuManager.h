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

class MenuManager
{
public:
    static MenuManager &instance();

    void setCurrentMenu(Menu menuType); // Use enum for setting current menu
    void displayCurrentMenu();
    void handleCurrentMenuInput();

    // Setting and getting the city for menus to use
    void setCity(City *city) { this->city = city; }
    City *getCity() const { return city; }

    void clearScreen() const { system("clear"); } // Utility function to clear screen

private:
    MenuManager(); // Private constructor for singleton pattern
    ~MenuManager();

    std::shared_ptr<IMenu> currentMenu;
    City *city = nullptr; // Store the reference to the city

    std::unordered_map<Menu, std::shared_ptr<IMenu>> menus; // Use Menu enum as the key for menus

    // Delete copy constructor and assignment operator to enforce singleton pattern
    MenuManager(const MenuManager &) = delete;
    MenuManager &operator=(const MenuManager &) = delete;
};

#endif // MENUMANAGER_H