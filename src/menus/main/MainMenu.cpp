#include "MainMenu.h"
#include "menus/base/MenuManager.h"
#include "city/CivZero.h"

MainMenu::MainMenu() : IMenu("Main Menu")
{
    // Initialize menu sections
    sections = {
        {"Options",
         {{'1', "🏗️ ", "Buildings Menu"},
          {'2', "🛠️ ", "Upgrades Menu"},
          {'3', "📜", "Policy Menu"},
          {'4', "💰", "Tax Menu"},
          {'5', "⏩", "Continue"}}},
        {"City Information",
         {{'6', "📊", "Show Stats"},
          {'d', "🏙️ ", "Display City"}}},
        {"Navigation",
         {{'q', "🚪", "Quit Game"}}}};
}

MainMenu::~MainMenu() {}

void MainMenu::display() const
{
    displayMenu(); // Use the inherited displayMenu() function to show the menu
}

void MainMenu::handleInput() const
{
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
        // Switch to the Buildings Menu
        MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
        break;
    case '2':
        // Switch to the Upgrades Menu
        MenuManager::instance().setCurrentMenu(Menu::UPGRADES);
        break;
    case '3':
        // Switch to the Policy Menu
        MenuManager::instance().setCurrentMenu(Menu::POLICY);
        break;
    case '4':
        // Switch to the Tax Menu
        MenuManager::instance().setCurrentMenu(Menu::TAX);
        break;
    case '5':
        // Switch to the Show Stats Menu
        // MenuManager::instance().setCurrentMenu(Menu::TAX);
        break;
    case 'd':
        // Switch to the Tax Menu
        MenuManager::instance().setCurrentMenu(Menu::DISPLAYCITY);
        break;
    case 'q':
        char confirm;
        std::cout << "Are you sure you want to quit the game (y/n):";
        std::cin >> confirm;
        if (confirm == 'y')
        {
            std::cout << "Quitting game..." << std::endl;
            CivZero::instance().quit();
        }
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
        break;
    }
}
