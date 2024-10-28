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
 * @brief Converts a numeric index (0-99) to a single character in an extended set.
 *
 * @param index Numeric index to convert (0-99).
 * @return char Corresponding character.
 */
char indexToExtendedChar(int index)
{
    if (index >= 0 && index <= 9)
    {
        return '0' + index;
    }
    else if (index >= 10 && index <= 35)
    {
        return 'A' + (index - 10);
    }
    else if (index >= 36 && index <= 61)
    {
        return 'a' + (index - 36);
    }
    else
    {
        const char specialChars[] = "!@#$%^&*()_+-=`~|\\{}[]:\";'<>?,./";
        int specialIndex = index - 62;
        if (specialIndex >= 0 && specialIndex < sizeof(specialChars) - 1)
        {
            return specialChars[specialIndex];
        }
    }
    throw std::out_of_range("Index out of range for extended character conversion");
}

/**
 * @brief Converts a single character in an extended set to a numeric index.
 *
 * @param ch Character to convert.
 * @return int Corresponding numeric index.
 */
int extendedCharToIndex(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 10;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return ch - 'a' + 36;
    }
    else
    {
        const std::string specialChars = "!@#$%^&*()_+-=`~|\\{}[]:\";'<>?,./";
        size_t pos = specialChars.find(ch);
        if (pos != std::string::npos)
        {
            return 62 + pos;
        }
    }
    throw std::invalid_argument("Invalid character for extended character conversion");
}

/**
 * @brief Constructor for DisplayCityMenu.
 * Initializes the menu with a single option to go back to the main menu.
 */
DisplayCityMenu::DisplayCityMenu() : IMenu("Display City")
{
    sections = {
        {"Display Options",
         {{'1', "🏠", "Display All Residential Buildings"},
          {'2', "🏢", "Display All Economic Buildings"},
          {'3', "🛠️ ", "Display All Services"},
          {'4', "⚡", "Display All Utilities"},
          {'5', "🏭", "Display All Industries"}}},
        {"Navigation", {{'q', "⬅️ ", "Back to Main Menu "}}}};
}

/**
 * @brief Destructor for DisplayCityMenu.
 */
DisplayCityMenu::~DisplayCityMenu() {}

/**
 * @brief Displays the menu and the city grid.
 * Calls displayMenu() to show menu options and displayCity() to render the city.
 */
void DisplayCityMenu::display() const
{
    displayMenu(); // Display menu options
    displayCity(); // Display the city layout
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

    // Loop over each row and column in the grid
    for (int row = 0; row < height; ++row)
    {
        std::cout << indexToExtendedChar(row) << DARK_GRAY << " ║ " << RESET;

        for (int col = 0; col < width; ++col)
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

    // Close the bottom border
    std::cout << "  ";
    printBottomBorder(width * 2 + 1);
}

/**
 * @brief Displays the city grid, filtering by entity type if specified.
 *
 * @tparam T The type of entity to display (e.g., ResidentialBuilding).
 */
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

    for (int row = 0; row < height; ++row)
    {
        std::cout << indexToExtendedChar(row) << DARK_GRAY << " ║ " << RESET;
        for (int col = 0; col < width; ++col)
        {
            Entity *entity = grid[row][col];
            // Only display if entity is of type T
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

    // Close the bottom border
    std::cout << "  ";
    printBottomBorder(width * 2 + 1);
}

/**
 * @brief Handles user input in the "Display City" menu.
 * Allows the user to filter by entity type or return to the main menu.
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

        clearScreen(); // Clear screen again before showing the filtered view

        switch (choice)
        {
        case '1': // Display All Residential Buildings
            displayCityByType<ResidentialBuilding>();
            break;
        case '2': // Display All Economic Buildings
            displayCityByType<EconomicBuilding>();
            break;
        case '3': // Display All Services
            displayCityByType<ServiceBuilding>();
            break;
        case '4': // Display All Utilities
            displayCityByType<Utility>();
            break;
        case '5': // Display All Industries
            displayCityByType<Industry>();
            break;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice();
            break;
        }

        displayPressEnterToContinue(); // Pause before redisplaying
    }
}