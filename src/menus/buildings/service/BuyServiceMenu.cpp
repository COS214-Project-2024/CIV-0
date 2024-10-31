#include "BuyServiceMenu.h"
#include "menus/base/MenuManager.h"

/**
 * @brief Constructor for BuyServiceMenu.
 * Initializes the base class BuyMenu.
 */
BuyServiceMenu::BuyServiceMenu() : BuyMenu() {}

/**
 * @brief Destructor for BuyServiceMenu.
 */
BuyServiceMenu::~BuyServiceMenu() {}

/**
 * @brief Override the entity type selection for service buildings.
 * @return The selected EntityType corresponding to Police Station, School, or Hospital.
 */
EntityType BuyServiceMenu::chooseEntityType()
{
    sections = {
        {"Options",
         {{'1', "🚓", "Police Station"},
          {'2', "🏫", "School"},
          {'3', "🏥", "Hospital"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Buildings Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};

    setHeading("Select Service Building Type");
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
            type = EntityType::POLICESTATION;
            choosing = false;
            break;
        case '2':
            type = EntityType::SCHOOL;
            choosing = false;
            break;
        case '3':
            type = EntityType::HOSPITAL;
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

void BuyServiceMenu::buildEntity(EntityType type, Size size, int xPos, int yPos)
{
    serviceManager.buildService(type, size, xPos, yPos);
}