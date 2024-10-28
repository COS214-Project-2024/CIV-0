#include "DisplayCityMenu.h"
#include "menus/base/MenuManager.h"
#include "city/CivZero.h"
#include "iterators/city/CityIterator.h"
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
    int width = city->getWidth();
    int height = city->getHeight();

    CityIterator it = city->createIterator(); // Get the iterator for the city

    // Display the grid headers with extended character labels
    std::cout << "    ";
    for (int i = 0; i < width; ++i)
    {
        std::cout << indexToExtendedChar(i) << " ";
    }
    std::cout << std::endl
              << "  ";
    printTopBorder(width * 2 + 1);

    int prevRow = -1;

    // Use the iterator to go through each cell in the city
    for (it.first(); it.hasNext(); it.next())
    {
        int row = it.getRow();
        int col = it.getCol();

        // Print a new line when moving to a new row
        if (row != prevRow)
        {
            if (prevRow != -1)
            {
                std::cout << DARK_GRAY << "║" << RESET << std::endl; // Close previous row
            }
            std::cout << indexToExtendedChar(row) << DARK_GRAY << " ║ " << RESET;
            prevRow = row;
        }

        // Display the symbol of the current entity
        Entity *entity = it.current();
        if (entity != nullptr)
        {
            std::cout << entity->getSymbol() << " ";
        }
        else
        {
            std::cout << DARK_GRAY << ". " << RESET;
        }
    }

    // Close the last row
    std::cout << DARK_GRAY << "║" << RESET << std::endl;
    std::cout << "  ";
    printBottomBorder(width * 2 + 1);
}

/**
 * @brief Handles user input in the "Display City" menu.
 * Allows the user to return to the main menu or display error for invalid choices.
 */
void DisplayCityMenu::handleInput()
{
    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice(); // Display error for invalid input
            break;
        }
    }
}
