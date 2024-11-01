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
         {{'q', "⬅️ ", "Back to Main Menu"}}}};
}

TaxMenu::~TaxMenu() {}

void TaxMenu::display() const
{
    displayMenu();
}

void TaxMenu::handleInput()
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
            City::instance()->setEconomicTax(City::instance()->getEconomicTax() + 1);
            if (City::instance()->getEconomicTax() > 100)
            {
                City::instance()->setEconomicTax(100);
            }
            displaySuccessMessage("Increased economic tax by 1%");
            displayPressEnterToContinue();
            choosing = false;
            break;
        case '2':
            City::instance()->setResidentialTax(City::instance()->getResidentialTax() + 1);
            if (City::instance()->getResidentialTax() > 100)
            {
                City::instance()->setResidentialTax(100);
            }
            displaySuccessMessage("Increased residential tax by 1%");
            displayPressEnterToContinue();
            choosing = false;
            break;
        case '3':
            City::instance()->setEconomicTax(City::instance()->getEconomicTax() - 1);
            if (City::instance()->getEconomicTax() < 0)
            {
                City::instance()->setEconomicTax(0);
            }
            displaySuccessMessage("Decreased economic tax by 1%");
            displayPressEnterToContinue();
            choosing = false;
            break;
        case '4':
            City::instance()->setResidentialTax(City::instance()->getResidentialTax() - 1);
            if (City::instance()->getResidentialTax() < 0)
            {
                City::instance()->setResidentialTax(0);
            }
            displaySuccessMessage("Decreased residential tax by 1%");
            displayPressEnterToContinue();
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
