#include "PolicyMenu.h"
#include "menus/base/MenuManager.h"
#include <iostream>

PolicyMenu::PolicyMenu() : IMenu("Policy Menu")
{
    sections = {
        {"Policy Menu",
         {{'1', "💧", "Apply new water policy"},
          {'2', "⚡", "Apply new electricity policy"},
          {'q', "🔙", "Back to Main Menu"}}}};
}

PolicyMenu::~PolicyMenu() {}

void PolicyMenu::display() const
{
    displayMenu(); // Use the inherited displayMenu() to show sections and options
}

void PolicyMenu::handleInput()
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
            std::cout << "Changing Policy 1..." << std::endl;
            choosing = false;
            break;
        case '2':
            std::cout << "Changing Policy 2..." << std::endl;
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
