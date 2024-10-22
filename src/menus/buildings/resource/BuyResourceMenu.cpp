#include "BuyResourceMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

BuyResourceMenu::BuyResourceMenu() : BuyMenu() {}

BuyResourceMenu::~BuyResourceMenu() {}

// Override the entity type selection for resource-producing buildings
EntityType BuyResourceMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🌲", "Wood Production"},
          {'2', "🪨 ", "Stone Quarry"},
          {'3', "🏗️ ", "Concrete Factory"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Building Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};

    setHeading("Select Resource Building Type");
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
            type = EntityType::WOODPRODUCER;
            choosing = false;
            break;
        case '2':
            type = EntityType::STONEPRODUCER;
            choosing = false;
            break;
        case '3':
            type = EntityType::CONCRETEPRODUCER;
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
