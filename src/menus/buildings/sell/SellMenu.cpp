#include "SellMenu.h"
#include "menus/base/MenuManager.h"
#include <iostream>
#include <vector>

/**
 * @brief Constructor for SellMenu.
 * Initializes the menu with options to sell specific or all buildings of a type.
 */
SellMenu::SellMenu() : IMenu() {}

/**
 * @brief Destructor for SellMenu.
 */
SellMenu::~SellMenu() {}

/**
 * @brief Displays the sell menu.
 */
void SellMenu::display() const {}

/**
 * @brief Handles user input for selling buildings.
 */
void SellMenu::handleInput()
{
    sections = {
        {"Options",
         {{'1', "🏠", "Sell a Specific Building"},
          {'2', "🏘️ ", "Sell All Buildings of a Type"}}},
        {"Navigation",
         {{'b', "🔙", "Back to Buildings Menu"},
          {'q', "🔙", "Back to Main Menu"}}}};
    setHeading("Sell Menu");
    clearScreen();
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            sellSpecificBuilding();
            choosing = false;
            break;
        case '2':
            sellAllBuildingsOfType();
            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
            choosing = false;
            break;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice();
            break;
        }
    }
}

/**
 * @brief Presents a menu for selecting and selling a specific building.
 */
void SellMenu::sellSpecificBuilding()
{
    sections.clear();
    sections.push_back({"Select Building to Sell", {}});

    // Assume we have a list of buildings the player owns
    std::vector<std::string> ownedBuildings = {"House #1", "Apartment #2", "Factory #3", "School #4"};
    char optionKey = '1';

    for (const std::string &building : ownedBuildings)
    {
        sections[0].options.push_back(Option{optionKey++, "🏠", building});
    }

    sections.push_back({"Navigation", {{'b', "🔙", "Back to Sell Menu"}, {'q', "🔙", "Back to Main Menu"}}});
    setHeading("Sell a Specific Building");
    clearScreen();
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        int index = choice - '1';
        if (index >= 0 && index < ownedBuildings.size())
        {
            std::vector<std::string> buildingToSell = {ownedBuildings[index]};
            confirmSell(buildingToSell);
            choosing = false;
        }
        else if (choice == 'b')
        {
            choosing = false;
        }
        else if (choice == 'q')
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

/**
 * @brief Presents a menu for selecting a building type and selling all buildings of that type.
 */
void SellMenu::sellAllBuildingsOfType()
{
    sections.clear();
    sections.push_back({"Select Building Type", {}});

    // Assume the player owns buildings of these types
    std::vector<EntityType> buildingTypes = {EntityType::HOUSE, EntityType::APARTMENT, EntityType::FACTORY};
    char optionKey = '1';

    for (EntityType type : buildingTypes)
    {
        sections[0].options.push_back(Option{optionKey++, "🏘️ ", entityTypeToString(type)});
    }

    sections.push_back({"Navigation", {{'b', "🔙", "Back to Sell Menu"}, {'q', "🔙", "Back to Main Menu"}}});
    setHeading("Sell All Buildings of a Type");
    clearScreen();
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        int index = choice - '1';
        if (index >= 0 && index < buildingTypes.size())
        {
            // Assume we can retrieve buildings of the selected type
            std::vector<std::string> buildingsToSell = {"House #1", "House #2", "House #3"};
            confirmSell(buildingsToSell);
            choosing = false;
        }
        else if (choice == 'b')
        {
            choosing = false;
        }
        else if (choice == 'q')
        {
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
        }
        else
        {
            displayInvalidChoice();
        }
    }
}

/**
 * @brief Confirms the sale of selected buildings.
 * @param buildingsToSell The list of buildings the user is about to sell.
 */
void SellMenu::confirmSell(const std::vector<std::string> &buildingsToSell)
{
    clearScreen();

    std::cout << BOLD_YELLOW << "You are about to sell the following buildings:" << RESET << std::endl;
    for (const std::string &building : buildingsToSell)
    {
        std::cout << " - " << building << std::endl;
    }

    displayChoiceMessagePrompt("Confirm sale (y/n):");
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y')
    {
        std::cout << BOLD_YELLOW << "Buildings sold successfully!" << RESET << std::endl;
        MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
    }
    else
    {
        std::cout << BOLD_YELLOW << "Sale cancelled." << RESET << std::endl;
    }

    display();
}
