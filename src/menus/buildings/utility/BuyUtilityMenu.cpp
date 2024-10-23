#include "BuyUtilityMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"

/**
 * @brief Constructor for BuyUtilityMenu.
 * Initializes the base BuyMenu for utility-building selection.
 */
BuyUtilityMenu::BuyUtilityMenu() : BuyMenu() {}

/**
 * @brief Destructor for BuyUtilityMenu.
 */
BuyUtilityMenu::~BuyUtilityMenu() {}

/**
 * @brief Displays the options for selecting a utility building type.
 * The user can choose between Power Plant, Water Supply, Waste Management, or Sewage System.
 * @return The selected EntityType for the utility building.
 */
EntityType BuyUtilityMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "⚡", "Power Plant"},
          {'2', "💧", "Water Supply"},
          {'3', "🗑️ ", "Waste Management"},
          {'4', "🚽", "Sewage System"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Buildings Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};

    setHeading("Select Utility Building Type");
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
            type = EntityType::POWERPLANT;
            choosing = false;
            break;
        case '2':
            type = EntityType::WATERSUPPLY;
            choosing = false;
            break;
        case '3':
            type = EntityType::WASTEMANAGMENT;
            choosing = false;
            break;
        case '4':
            type = EntityType::SEWAGESYSTEM;
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
