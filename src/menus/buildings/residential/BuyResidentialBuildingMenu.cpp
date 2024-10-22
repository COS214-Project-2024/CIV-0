#include "BuyResidentialBuildingMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

BuyResidentialBuildingMenu::BuyResidentialBuildingMenu() : BuyMenu() {}

BuyResidentialBuildingMenu::~BuyResidentialBuildingMenu() {}

// Override the entity type selection for residential buildings
EntityType BuyResidentialBuildingMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🏠", "House"},
          {'2', "🏢", "Apartment"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Building Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};

    setHeading("Select Residential Building Type");
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
            type = EntityType::HOUSE;
            choosing = false;
            break;
        case '2':
            type = EntityType::APARTMENT;
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
