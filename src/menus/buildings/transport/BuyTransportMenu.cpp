#include "BuyTransportMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

/**
 * @brief Constructor for BuyTransportMenu.
 * Initializes the base BuyMenu for transport-building selection.
 */
BuyTransportMenu::BuyTransportMenu() : BuyMenu() {}

/**
 * @brief Destructor for BuyTransportMenu.
 */
BuyTransportMenu::~BuyTransportMenu() {}

/**
 * @brief Displays the options for selecting a transport building type.
 * The user can choose between Bus Stop, Airport, or Train Station.
 * @return The selected EntityType for the transport building.
 */
EntityType BuyTransportMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🚌", "Bus Stop"},
          {'2', "✈️ ", "Airport"},
          {'3', "🚆", "Train Station"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Buildings Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};

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

void BuyTransportMenu::buildEntity(EntityType type, Size size, int xPos, int yPos)
{
}