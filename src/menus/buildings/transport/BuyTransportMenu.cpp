#include "BuyTransportMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

BuyTransportMenu::BuyTransportMenu() : BuyMenu() {}

BuyTransportMenu::~BuyTransportMenu() {}

// Override the entity type selection for transport buildings
EntityType BuyTransportMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🚌", "Bus Stop"},
          {'2', "✈️ ", "Airport"},
          {'3', "🚆", "Train Station"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Building Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};

    setHeading("Select Transport Building Type");
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
            type = EntityType::BUSSTOP;
            choosing = false;
            break;
        case '2':
            type = EntityType::AIRPORT;
            choosing = false;
            break;
        case '3':
            type = EntityType::TRAINSTATION;
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
