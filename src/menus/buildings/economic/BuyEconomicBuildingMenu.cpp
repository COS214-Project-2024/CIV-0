#include "BuyEconomicBuildingMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

BuyEconomicBuildingMenu::BuyEconomicBuildingMenu() : BuyMenu() {}

BuyEconomicBuildingMenu::~BuyEconomicBuildingMenu() {}

// Override the entity type selection for economic buildings
EntityType BuyEconomicBuildingMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🏢", "Office"},
          {'2', "🏬", "Shopping Mall"},
          {'3', "🏭", "Factory"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Building Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};

    setHeading("Select Economic Building Type");
    clearScreen();
    displayMenu();

    EntityType type;
    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            type = EntityType::OFFICE;
            choosing = false;
            break;
        case '2':
            type = EntityType::SHOPPINGMALL;
            choosing = false;
            break;
        case '3':
            type = EntityType::FACTORY;
            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
            choosing = false;
            hasExited = true;
            break;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            hasExited = true;
            break;
        default:
            displayInvalidChoice();
            break;
        }
    }

    return type;
}
