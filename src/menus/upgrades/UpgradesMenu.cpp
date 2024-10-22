#include "UpgradesMenu.h"
#include "menus/base/MenuManager.h"
#include <iostream>

UpgradesMenu::UpgradesMenu() : IMenu("Upgrades Menu")
{
    sections = {
        {"Upgrades Menu",
         {{'1', "💧", "Upgrade Water Supply"},
          {'2', "⚡", "Upgrade Power Plant"},
          {'3', "🚮", "Upgrade Waste Management System"},
          {'4', "🚰", "Upgrade Sewage System"},
          {'q', "🔙", "Back to Main Menu"}}}};
}

UpgradesMenu::~UpgradesMenu() {}

void UpgradesMenu::display() const
{
    displayMenu();
}

void UpgradesMenu::handleInput()
{
    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            std::cout << "Upgrading Building 1..." << std::endl;
            choosing = false;
            break;
        case '2':
            std::cout << "Upgrading Building 2..." << std::endl;
            choosing = false;
            break;
        case 'q':
            // Switch back to the Main Menu
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice();
        }
    }
}
