#include "MenuManager.h"

// Singleton instance method
MenuManager &MenuManager::instance()
{
    static MenuManager instance;
    return instance;
}

// Private constructor
MenuManager::MenuManager()
{
    // Initialize all the menus and store them in the map with the enum as the key
    menus[Menu::MAIN] = std::make_shared<MainMenu>();
    menus[Menu::BUILDINGS] = std::make_shared<BuildingsMenu>();
    menus[Menu::POLICY] = std::make_shared<PolicyMenu>();
    menus[Menu::UPGRADES] = std::make_shared<UpgradesMenu>();
    menus[Menu::TAX] = std::make_shared<TaxMenu>();
    menus[Menu::DISPLAYCITY] = std::make_shared<DisplayCityMenu>();

    // Set the default menu to MainMenu
    setCurrentMenu(Menu::MAIN);
}

// Destructor
MenuManager::~MenuManager() {}

// Set the current menu by enum key
void MenuManager::setCurrentMenu(Menu menuType)
{
    if (menus.find(menuType) != menus.end())
    {
        currentMenu = menus[menuType];
    }
    else
    {
        std::cerr << "Menu not found!" << std::endl;
    }
}

// Display the current menu
void MenuManager::displayCurrentMenu()
{
    if (currentMenu)
    {
        currentMenu->display();
    }
    else
    {
        std::cout << "No menu is set." << std::endl;
    }
}

// Handle the input for the current menu
void MenuManager::handleCurrentMenuInput()
{
    if (currentMenu)
    {
        currentMenu->handleInput();
    }
}
