#include "DisplayCityMenu.h"
#include "menus/base/MenuManager.h"
#include "city/CivZero.h"
#include "iterators/city/CityIterator.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/building/economic/EconomicBuilding.h"
#include "entities/building/service/ServiceBuilding.h"
#include "entities/industry/base/Industry.h"
#include "entities/utility/base/Utility.h"
#include "entities/road/Road.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Constructor for DisplayCityMenu.
 * Initializes the menu with options for different display types and a back option.
 */
DisplayCityMenu::DisplayCityMenu() : IMenu("Display City")
{
    sections = {
        {"Display Options",
         {{'r', "🏠", "Display All Residential Buildings"},
          {'e', "🏢", "Display All Economic Buildings"},
          {'s', "🛠️ ", "Display All Services"},
          {'u', "⚡", "Display All Utilities"},
          {'i', "🏭", "Display All Industries"},
          {'t', "🚗", "Display All Trasnports"},
          {'d', "🌆", "Display Whole City"}}},
        {"Navigation", {{'q', "⬅️ ", "Back to Main Menu "}}}};
}

/**
 * @brief Destructor for DisplayCityMenu.
 */
DisplayCityMenu::~DisplayCityMenu() {}

/**
 * @brief Displays the menu and the city grid based on the selected display mode.
 */
void DisplayCityMenu::display() const
{
    displayMenu();         // Display menu options
    displayFilteredCity(); // Display the city layout based on current mode
}

/**
 * @brief Chooses the correct display method based on the current display mode.
 */
void DisplayCityMenu::displayFilteredCity() const
{
    switch (currentDisplayMode)
    {
    case DisplayMode::WHOLE_CITY:
        displayCity();
        break;
    case DisplayMode::RESIDENTIAL:
        displayCityByType<ResidentialBuilding>();
        break;
    case DisplayMode::ECONOMIC:
        displayCityByType<EconomicBuilding>();
        break;
    case DisplayMode::SERVICE:
        displayCityByType<ServiceBuilding>();
        break;
    case DisplayMode::UTILITY:
        displayCityByType<Utility>();
        break;
    case DisplayMode::INDUSTRY:
        displayCityByType<Industry>();
        break;
    case DisplayMode::TRANSPORT:
        displayCityByType<Transport>();
        break;
    }
}

void DisplayCityMenu::displayCity() const
{
    City *city = City::instance();
    const auto &grid = city->getGrid();
    int width = city->getWidth();
    int height = city->getHeight();

    // Display the grid headers with extended character labels
    std::cout << "    ";
    for (int i = 0; i < width; ++i)
    {
        std::cout << indexToExtendedChar(i) << " ";
    }
    std::cout << std::endl
              << "  ";

    printTopBorder(width * 2 + 1);

    for (int col = 0; col < height; ++col)
    {
        std::cout << indexToExtendedChar(col) << DARK_GRAY << " ║ " << RESET;

        for (int row = 0; row < width; ++row)
        {
            Entity *entity = grid[row][col];
            if (entity != nullptr)
            {
                std::cout << entity->getSymbol() << " ";
            }
            else
            {
                std::cout << DARK_GRAY << ". " << RESET;
            }
        }

        std::cout << DARK_GRAY << "║" << RESET << std::endl;
    }

    std::cout << "  ";
    printBottomBorder(width * 2 + 1);
}

template <typename T>
void DisplayCityMenu::displayCityByType() const
{
    City *city = City::instance();
    const auto &grid = city->getGrid();
    int width = city->getWidth();
    int height = city->getHeight();

    // Display the grid headers with extended character labels
    std::cout << "    ";
    for (int i = 0; i < width; ++i)
    {
        std::cout << indexToExtendedChar(i) << " ";
    }
    std::cout << std::endl
              << "  ";
    printTopBorder(width * 2 + 1);

    for (int col = 0; col < height; ++col)
    {
        std::cout << indexToExtendedChar(col) << DARK_GRAY << " ║ " << RESET;

        for (int row = 0; row < width; ++row)
        {
            Entity *entity = grid[row][col];
            if (entity != nullptr && (dynamic_cast<T *>(entity) || dynamic_cast<Road *>(entity)))
            {
                std::cout << entity->getSymbol() << " ";
            }
            else
            {
                std::cout << DARK_GRAY << ". " << RESET;
            }
        }

        std::cout << DARK_GRAY << "║" << RESET << std::endl;
    }

    std::cout << "  ";
    printBottomBorder(width * 2 + 1);
}

/**
 * @brief Handles user input in the "Display City" menu.
 * Allows the user to select a display mode or return to the main menu.
 */
void DisplayCityMenu::handleInput()
{
    bool choosing = true;

    while (choosing)
    {
        clearScreen(); // Clear screen at the start of each choice
        display();     // Display city and menu options
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case 'r': // Display All Residential Buildings
            currentDisplayMode = DisplayMode::RESIDENTIAL;
            break;
        case 'e': // Display All Economic Buildings
            currentDisplayMode = DisplayMode::ECONOMIC;
            break;
        case 's': // Display All Services
            currentDisplayMode = DisplayMode::SERVICE;
            break;
        case 'u': // Display All Utilities
            currentDisplayMode = DisplayMode::UTILITY;
            break;
        case 'i': // Display All Industries
            currentDisplayMode = DisplayMode::INDUSTRY;
            break;
        case 'd': // Display Whole City
            currentDisplayMode = DisplayMode::WHOLE_CITY;
            break;
        case 't': // Display Trasnports
            currentDisplayMode = DisplayMode::TRANSPORT;
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
