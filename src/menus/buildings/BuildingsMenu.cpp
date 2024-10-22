#include "BuildingsMenu.h"
#include "menus/base/MenuManager.h"
#include <iostream>

BuildingsMenu::BuildingsMenu() : IMenu("Buildings Menu")
{
    // Initialize menu sections
    sections = {
        {"Buy Buildings",
         {{'1', "🚗", "Buy Transport"},
          {'2', "🏢", "Buy Economic Building"},
          {'3', "🏠", "Buy Residential Building"},
          {'4', "🏥", "Buy Service Building"},
          {'5', "🌳", "Buy Amenity"},
          {'6', "⚡", "Buy Utility"},
          {'7', "🛠️ ", "Buy Resource"}}},
        {"Sell Buildings",
         {{'8', "🏚️ ", "Sell Building"}}},
        {"Navigation",
         {{'q', "🔙", "Back to Main Menu"}}}};
}

BuildingsMenu::~BuildingsMenu() {}

void BuildingsMenu::display() const
{
    displayMenu(); // Use the inherited displayMenu() function to show the menu
}

void BuildingsMenu::handleInput()
{
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
        MenuManager::instance().setCurrentMenu(Menu::BUY_TRANSPORT);
        break;
    case '2':
        MenuManager::instance().setCurrentMenu(Menu::BUY_ECONOMIC_BUILDING);
        break;
    case '3':
        MenuManager::instance().setCurrentMenu(Menu::BUY_RESIDENTIAL_BUILDING);
        break;
    case '4':
        MenuManager::instance().setCurrentMenu(Menu::BUY_SERVICE);
        break;
    case '5':
        MenuManager::instance().setCurrentMenu(Menu::BUY_AMENITY);
        break;
    case '6':
        MenuManager::instance().setCurrentMenu(Menu::BUY_UTILITY);
        break;
    case '7':
        MenuManager::instance().setCurrentMenu(Menu::BUY_RESOURCE);
        break;
    case '8':

        break;
    case 'q':
        MenuManager::instance().setCurrentMenu(Menu::MAIN);
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
        break;
    }
}
