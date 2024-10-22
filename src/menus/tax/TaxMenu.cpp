#include "TaxMenu.h"
#include "menus/base/MenuManager.h"
#include <iostream>

TaxMenu::TaxMenu() : IMenu("Tax Menu")
{
    sections = {
        {"Increase Taxes",
         {{'1', "📈", "Increase economic tax by 1%"},
          {'2', "📈", "Increase residential tax by 1%"}}},
        {"Decrease Taxes",
         {{'3', "📉", "Decrease economic tax by 1%"},
          {'4', "📉", "Decrease residential tax by 1%"}}},
        {"Navigation",
         {{'q', "🔙", "Back to Main Menu"}}}};
}

TaxMenu::~TaxMenu() {}

void TaxMenu::display() const
{
    displayMenu();
}

void TaxMenu::handleInput()
{
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
        std::cout << "Adjusting Tax Rate 1..." << std::endl;
        break;
    case '2':
        std::cout << "Adjusting Tax Rate 2..." << std::endl;
        break;
    case 'q':
        // Switch back to the Main Menu
        MenuManager::instance().setCurrentMenu(Menu::MAIN);
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
    }
}
