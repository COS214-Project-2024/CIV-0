#include "CityNameMenu.h"
#include "menus/base/MenuManager.h"
#include "city/City.h"
#include "city/CivZero.h"
#include <iostream>
#include <limits>
#include <string>

/**
 * @brief Constructor for CityNameMenu.
 */
CityNameMenu::CityNameMenu()
{
    // Set the menu heading
    setHeading("Enter City Name");
}

/**
 * @brief Destructor for CityNameMenu.
 */
CityNameMenu::~CityNameMenu() {}

/**
 * @brief Displays the menu to the user.
 */
void CityNameMenu::display() const
{
    // You can customize the display if needed
    displayMenu();
}

/**
 * @brief Handles user input for the menu.
 */
void CityNameMenu::handleInput()
{
    std::string cityName;
    bool validInput = false;

    while (!validInput)
    {
        displayChoiceMessagePrompt("Please enter the name of your city: ");

        // Clear any remaining input
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore();
        }

        std::getline(std::cin, cityName);

        // Trim whitespace from cityName if needed
        cityName.erase(0, cityName.find_first_not_of(' ')); // Left trim
        cityName.erase(cityName.find_last_not_of(' ') + 1); // Right trim

        if (cityName.empty())
        {
            displayErrorMessage("City name cannot be empty. Please try again.");
        }
        else
        {
            validInput = true;
        }
    }

    // Set the city name in the City instance
    City::instance()->setCityName(cityName);

    // Initialize the city
    CityManager manager;
    manager.initializeCity();

    // Proceed to the Main Menu
    MenuManager::instance().setCurrentMenu(Menu::MAIN);
}
