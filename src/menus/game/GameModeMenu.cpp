#include "GameModeMenu.h"
#include "menus/base/MenuManager.h"
#include "city/City.h"
#include "city/CivZero.h"
#include <iostream>
#include <limits>

/**
 * @brief Constructor for GameModeMenu.
 */
GameModeMenu::GameModeMenu() : hasDisplayedWelcomeMessage(false)
{
    // Set the menu heading
    setHeading("Select Game Mode");

    // Add the options to the menu
    Section section;
    section.heading = "Choose how to play the game:";

    Option option1;
    option1.key = '1';
    option1.icon = "🏙️ "; // City icon
    option1.text = "Start Normal Game";
    section.options.push_back(option1);

    Option option2;
    option2.key = '2';
    option2.icon = "🛣️ "; // Road icon
    option2.text = "Generate Roads";
    section.options.push_back(option2);

    Option option3;
    option3.key = '3';
    option3.icon = "🌆"; // Cityscape icon
    option3.text = "Generate Random City";
    section.options.push_back(option3);

    Option option4;
    option4.key = '4';
    option4.icon = "🏗️ "; // Building construction icon
    option4.text = "Demo City";
    section.options.push_back(option4);

    Option option5;
    option5.key = 'q';
    option5.icon = "🚪";
    option5.text = "Quit Game";
    section.options.push_back(option5);

    sections.push_back(section);
}

/**
 * @brief Destructor for GameModeMenu.
 */
GameModeMenu::~GameModeMenu() {}

/**
 * @brief Displays the menu to the user.
 */
void GameModeMenu::display() const
{
    if (!hasDisplayedWelcomeMessage)
    {
        // Display welcome message
        clearScreen();
        std::cout << BOLD_WHITE << centerText("Welcome to CivZero!", 80) << RESET << "\n";
        std::cout << DARK_GRAY << repeat("─", 80) << RESET << "\n";
        std::cout << NORMAL_WHITE << centerText("A city-building simulation game", 80) << RESET << "\n";
        displayPressEnterToContinue();

        // Set the flags
        hasDisplayedWelcomeMessage = true;

        clearScreen();
        displayMenu();
    }
    else
    {
        // Display the game mode menu
        displayMenu();
    }
}

/**
 * @brief Handles user input for the menu.
 */
void GameModeMenu::handleInput()
{
    bool choosing = true;

    while (choosing)
    {
        displayChoicePrompt();

        char choice;
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            // Start normal game by asking for city name
            MenuManager::instance().setCurrentMenu(Menu::CITY_NAME);
            choosing = false;
            break;

        case '2':
            // Generate roads method
            City::instance()->reset(CivZero::GRID_SIZE, CivZero::GRID_SIZE);
            City::instance()->setCityName("Random Roads City");

            {
                CityManager manager;
                manager.generateRandomRoads();
                manager.updateCity();
            }

            // Now set the next menu to the MainMenu
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;

        case '3':
            // Generate random city
            City::instance()->reset(CivZero::GRID_SIZE, CivZero::GRID_SIZE);
            City::instance()->setCityName("Random City");

            {
                CityManager manager;
                manager.generateCity();
                manager.updateCity();
            }

            // Now set the next menu to the MainMenu
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;

        case '4':
            // Demo city
            City::instance()->reset(CivZero::GRID_SIZE, CivZero::GRID_SIZE);
            City::instance()->setCityName("DEMO City");

            {
                CityManager manager;
                manager.generateDemoCity();
                manager.updateCity();
            }

            // Now set the next menu to the MainMenu
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        case 'q':
            char confirm;
            displayChoiceMessagePrompt("Are you sure you want to quit the game (y/n): ");
            std::cin >> confirm;
            if (confirm == 'y')
            {
                displaySuccessMessage("Quitting game...");
                CivZero::instance().quit(); // Call the quit method from CivZero
                choosing = false;
            }
            break;
        default:
            displayInvalidChoice(); // Handle invalid input
            displayPressEnterToContinue();
            break;
        }
    }
}