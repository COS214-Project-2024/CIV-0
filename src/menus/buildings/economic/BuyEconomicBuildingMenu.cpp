#include "BuyEconomicBuildingMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

/**
 * @brief Constructor for BuyEconomicBuildingMenu.
 * Initializes the base BuyMenu and sets up any economic building-related configurations.
 */
BuyEconomicBuildingMenu::BuyEconomicBuildingMenu() : BuyMenu() {}

/**
 * @brief Destructor for BuyEconomicBuildingMenu.
 */
BuyEconomicBuildingMenu::~BuyEconomicBuildingMenu() {}

/**
 * @brief Allows the user to choose an economic building type from the options available.
 * Displays options such as Office, Shopping Mall, and Factory.
 * @return The selected EntityType corresponding to the chosen economic building.
 */
EntityType BuyEconomicBuildingMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🏢", "Office"},
          {'2', "🏬", "Shopping Mall"},
          {'3', "🏭", "Factory"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Buildings Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};

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

void BuyEconomicBuildingMenu::buildEntity(EntityType type, Size size, int xPos, int yPos)
{
}