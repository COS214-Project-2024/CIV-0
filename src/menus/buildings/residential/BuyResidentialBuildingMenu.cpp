#include "BuyResidentialBuildingMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

/**
 * @brief Constructor for BuyResidentialBuildingMenu.
 * Initializes the base BuyMenu for residential building selection.
 */
BuyResidentialBuildingMenu::BuyResidentialBuildingMenu() : BuyMenu() {}

/**
 * @brief Destructor for BuyResidentialBuildingMenu.
 */
BuyResidentialBuildingMenu::~BuyResidentialBuildingMenu() {}

/**
 * @brief Displays the options for selecting a residential building type.
 * The user can choose between House or Apartment.
 * @return The selected EntityType for the residential building.
 */
EntityType BuyResidentialBuildingMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🏠", "House"},
          {'2', "🏢", "Apartment"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Buildings Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};

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

void BuyResidentialBuildingMenu::buildEntity(EntityType type, Size size, int xPos, int yPos)
{
}