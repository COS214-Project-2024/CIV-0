#include "DemolishMenu.h"
#include "menus/base/MenuManager.h"
#include "iterators/city/CityIterator.h"
#include <iostream>

/**
 * @brief Constructor for DemolishMenu.
 * Initializes the menu with options to demolish specific or all buildings of a type.
 */
DemolishMenu::DemolishMenu() : IMenu("Demolish Menu")
{
    setHeading("Demolish Menu");
}

/**
 * @brief Destructor for DemolishMenu.
 */
DemolishMenu::~DemolishMenu() {}

/**
 * @brief Displays the demolish menu.
 */
void DemolishMenu::display() const
{
    clearScreen();
    displayMenu();
}

/**
 * @brief Handles user input for demolishing buildings.
 */
void DemolishMenu::handleInput()
{
    sections = {
        {"Options",
         {{'1', "🔨", "Demolish a Specific Building"},
          {'2', "🏚️ ", "Demolish All Buildings of a Type"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Buildings Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};
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
            demolishSpecificBuilding();
            choosing = false;
            break;
        case '2':
            demolishAllBuildingsOfType();
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
 * @brief Presents a menu for selecting and demolishing a specific building.
 */
void DemolishMenu::demolishSpecificBuilding()
{
    sections.clear();
    sections.push_back({"Select Building to Demolish", {}});

    City *city = City::instance();
    CityIterator cityIterator(city->getGrid());
    std::vector<std::pair<int, int>> buildingPositions;
    char optionKey = '1';

    // Populate menu with buildings currently in the city
    for (cityIterator.first(); cityIterator.hasNext(); cityIterator.next())
    {
        Entity *entity = cityIterator.current();
        if (entity)
        {
            buildingPositions.push_back({cityIterator.getRow(), cityIterator.getCol()});
            std::string buildingLabel = entityTypeToString(entity->getType()) + " (" + coordinatesToLabel(cityIterator.getRow(), cityIterator.getCol()) + ")";
            sections[0].options.push_back(Option{optionKey++, "🏠", buildingLabel});
        }
    }

    sections.push_back({"Navigation", {{'b', "🔙", "Back to Demolish Menu"}, {'q', "🔙", "Back to Main Menu"}}});
    setHeading("Demolish a Specific Building");
    clearScreen();
    displayMenu();

    bool choosing = true;
    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        int index = choice - '1';
        if (index >= 0 && index < buildingPositions.size())
        {
            std::vector<std::pair<int, int>> positionToDemolish = {buildingPositions[index]};
            confirmDemolish(positionToDemolish);
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
 * @brief Presents a menu for selecting a building type and demolishing all buildings of that type.
 */
void DemolishMenu::demolishAllBuildingsOfType()
{
    sections.clear();
    sections.push_back({"Select Building Type", {}});

    std::vector<EntityType> buildingTypes = {EntityType::HOUSE, EntityType::APARTMENT, EntityType::FACTORY};
    char optionKey = '1';

    for (EntityType type : buildingTypes)
    {
        sections[0].options.push_back(Option{optionKey++, "🏚️ ", entityTypeToString(type)});
    }

    sections.push_back({"Navigation", {{'b', "🔙", "Back to Demolish Menu"}, {'q', "🔙", "Back to Main Menu"}}});
    setHeading("Demolish All Buildings of a Type");
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
            EntityType selectedType = buildingTypes[index];

            // Use CityManager to get positions of all buildings of the selected type
            std::vector<std::pair<int, int>> positionsToDemolish;
            CityIterator cityIterator(City::instance()->getGrid());
            for (cityIterator.first(); cityIterator.hasNext(); cityIterator.next())
            {
                Entity *entity = cityIterator.current();
                if (entity && entity->getType() == selectedType)
                {
                    positionsToDemolish.push_back({cityIterator.getRow(), cityIterator.getCol()});
                }
            }

            confirmDemolish(positionsToDemolish);
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
 * @brief Confirms the demolition of selected buildings.
 * @param positionsToDemolish The list of building positions to be demolished.
 */
void DemolishMenu::confirmDemolish(const std::vector<std::pair<int, int>> &positionsToDemolish)
{
    clearScreen();

    std::cout << BOLD_YELLOW << "You are about to demolish the following buildings:" << RESET << std::endl;
    for (const auto &[x, y] : positionsToDemolish)
    {
        Entity *entity = City::instance()->getEntity(x, y);
        if (entity)
        {
            std::cout << " - " << entityTypeToString(entity->getType()) << " at " << coordinatesToLabel(x, y) << std::endl;
        }
    }

    displayChoiceMessagePrompt("Confirm demolition (y/n): ");
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y')
    {
        for (const auto &[x, y] : positionsToDemolish)
        {
            cityManager.sellBuilding(x, y);
        }
        displaySuccessMessage("Buildings demolished successfully!");
        displayPressEnterToContinue();
    }
    else
    {
        displayErrorMessage("Demolition cancelled.");
    }
}
