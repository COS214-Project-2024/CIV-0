#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <map>
#include <string>
#include "IMenu.h"
#include "city/City.h" // Include the City class

class MenuManager
{
public:
    static MenuManager &getInstance();

    // Prevent copying and assignment
    MenuManager(const MenuManager &) = delete;
    MenuManager &operator=(const MenuManager &) = delete;

    // Set the reference to the city
    void setCity(City *city);

    void setCurrentMenu(const std::string &menuName);
    void displayCurrentMenu();
    void handleCurrentMenuInput();

private:
    // Private constructor
    MenuManager();
    ~MenuManager();

    std::map<std::string, IMenu *> menus;
    IMenu *currentMenu;
    City *city; // Pointer to the City object
};

#endif // MENUMANAGER_H
