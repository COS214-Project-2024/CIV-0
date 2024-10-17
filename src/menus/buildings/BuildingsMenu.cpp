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
          {'6', "⚡", "Buy Utility"}}},
        {"Sell Buildings",
         {{'7', "🏚️ ", "Sell Building"}}},
        {"Navigation",
         {{'q', "🔙", "Back to Main Menu"}}}};
}

BuildingsMenu::~BuildingsMenu() {}

void BuildingsMenu::display() const
{
    displayMenu(); // Use the inherited displayMenu() function to show the menu
}

void BuildingsMenu::handleInput() const
{
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
        // Action for building a house
        std::cout << "Building a house..." << std::endl;
        break;
    case '2':
        // Action for building a factory
        std::cout << "Building a factory..." << std::endl;
        break;
    case '3':
        // Action for building a commercial building
        std::cout << "Building a commercial building..." << std::endl;
        break;
    case 'q':
        // Go back to the main menu
        MenuManager::instance().setCurrentMenu(Menu::MAIN);
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
        break;
    }
}
