#include "BuyResourceMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

/**
 * @brief Constructor for BuyResourceMenu.
 * Initializes the base BuyMenu for resource-producing building selection.
 */
BuyResourceMenu::BuyResourceMenu() : BuyMenu() {}

/**
 * @brief Destructor for BuyResourceMenu.
 */
BuyResourceMenu::~BuyResourceMenu() {}

/**
 * @brief Displays the options for selecting a resource-producing building type.
 * The user can choose between Wood Production, Stone Quarry, or Concrete Factory.
 * @return The selected EntityType for the resource-producing building.
 */
EntityType BuyResourceMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🌲", "Wood Production"},
          {'2', "🪨 ", "Stone Quarry"},
          {'3', "🏗️ ", "Concrete Factory"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Buildings Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};

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

void BuyResourceMenu::buildEntity(EntityType type, Size size, int xPos, int yPos)
{
    resourceManager.buildIndustry(type, size, xPos, yPos);
}