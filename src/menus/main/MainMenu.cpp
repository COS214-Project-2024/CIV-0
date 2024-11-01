#include "MainMenu.h"
#include "menus/base/MenuManager.h"
#include "city/CivZero.h"

/**
 * @brief Constructor for MainMenu.
 * Initializes the menu options and navigation for the Main Menu.
 */
MainMenu::MainMenu() : IMenu("Main Menu")
{
    // Initialize menu sections
    sections = {
        {"Options",
         {{'1', "🏗️ ", "Buildings Menu"},
          {'2', "🛣️ ", "Buy Road Menu"},
          {'3', "🛠️ ", "Upgrades Menu"},
          {'4', "📜", "Policy Menu"},
          {'5', "💰", "Tax Menu"},
          {'c', "⏩", "Continue"}}},
        {"City Information",
         {{'s', "📊", "Show Stats"},
          {'d', "🏙️ ", "Display City"}}},
        {"Navigation",
         {{'q', "🚪", "Quit Game"}}}};
}

/**
 * @brief Destructor for MainMenu.
 * Cleans up any resources used by the Main Menu.
 */
MainMenu::~MainMenu() {}

/**
 * @brief Displays the Main Menu.
 * Uses the inherited displayMenu() method to render the menu with all the options.
 */
void MainMenu::display() const
{
    displayMenu(); // Use the inherited displayMenu() function to show the menu
}

/**
 * @brief Handles user input in the Main Menu.
 *
 * This function manages the logic for navigating between the various menus or exiting the game
 * based on the player's input.
 */
void MainMenu::handleInput()
{
    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt(); // Display the prompt asking for input
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            // Switch to the Buildings Menu
            MenuManager::instance().setCurrentMenu(Menu::BUILDINGS);
            choosing = false;
            break;
        case '2':
            // Switch to the Upgrades Menu
            MenuManager::instance().setCurrentMenu(Menu::BUY_ROAD);
            choosing = false;
            break;
        case '3':
            // Switch to the Upgrades Menu
            MenuManager::instance().setCurrentMenu(Menu::UPGRADES);
            choosing = false;
            break;
        case '4':
            // Switch to the Policy Menu
            MenuManager::instance().setCurrentMenu(Menu::POLICY);
            choosing = false;
            break;
        case '5':
            // Switch to the Tax Menu
            MenuManager::instance().setCurrentMenu(Menu::TAX);
            choosing = false;
            break;
        case 's':
            // Switch to the Stats Menu
            MenuManager::instance().setCurrentMenu(Menu::STATS);
            choosing = false;
            break;
        case 'c':
            // Logic for continuing the game can be added here
            cityManager.updateCity();
            displaySuccessMessage("The Sun has risen for another day 🌅 :)");
            displayPressEnterToContinue();
            clearScreen();
            displayMenu();
            break;
        case 'd':
            // Switch to the Display City Menu
            MenuManager::instance().setCurrentMenu(Menu::DISPLAYCITY);
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
            break;
        }
    }
}
