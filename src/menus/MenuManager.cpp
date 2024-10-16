#include "MenuManager.h"
#include "MainMenu.h"

// Initialize the static instance
MenuManager &MenuManager::getInstance()
{
    static MenuManager instance; // This creates the single instance
    return instance;
}

// Private constructor to prevent instantiation from outside
MenuManager::MenuManager()
{
    // Initialize menus and set the default one
    menus["main"] = new MainMenu();
    // menus["building"] = new BuildingMenu();
    currentMenu = menus["main"];
}

MenuManager::~MenuManager()
{
    // Clean up memory for all menus
    for (auto &pair : menus)
    {
        delete pair.second;
    }
}

void MenuManager::setCity(City *city)
{
    this->city = city;
}

void MenuManager::setCurrentMenu(const std::string &menuName)
{
    if (menus.find(menuName) != menus.end())
    {
        currentMenu = menus[menuName];
    }
    else
    {
        std::cout << "Menu not found!" << std::endl;
    }
}

void MenuManager::displayCurrentMenu()
{
    if (currentMenu)
    {
        // Ensure the current menu has access to the city (if needed)
        currentMenu->setCity(city); // Assuming menus can accept a City reference
        currentMenu->display();
    }
}

void MenuManager::handleCurrentMenuInput()
{
    currentMenu->handleInput();
}
