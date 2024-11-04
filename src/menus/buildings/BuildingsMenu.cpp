#include "BuildingsMenu.h"
#include "menus/base/MenuManager.h"
#include "utils/ConfigManager.h"
#include "BuildingsStatMenu.h"
#include <iostream>

/**
 * @brief Constructs the BuildingsMenu and initializes its sections.
 * The menu is divided into sections for buying, selling, and viewing stats of buildings.
 */
BuildingsMenu::BuildingsMenu() : IMenu("Buildings Menu")
{
    // Initialize menu sections
    sections = {
        {"Buy Buildings", // Section for buying buildings
         {{'1', "🚗", "Buy Transport"},
          {'2', "🏢", "Buy Economic Building"},
          {'3', "🏠", "Buy Residential Building"},
          {'4', "🏥", "Buy Service Building"},
          {'5', "🌳", "Buy Amenity"},
          {'6', "⚡", "Buy Utility"},
          {'7', "🛠️ ", "Buy Resource"}}},
        {"Demolish Buildings", // Section for demolishing buildings
         {{'8', "🏚️ ", "Demolish Building"}}},
        {"View Building Stats", // Section for viewing stats of different building types
         {{'a', "🔍", "View Transport Stats"},
          {'b', "🔍", "View Economic Building Stats"},
          {'c', "🔍", "View Residential Building Stats"},
          {'d', "🔍", "View Service Building Stats"},
          {'e', "🔍", "View Amenity Stats"},
          {'f', "🔍", "View Utility Stats"},
          {'g', "🔍", "View Resource Stats"}}},
        {"Navigation", // Section for navigating back to the main menu
         {{'q', "⬅️ ", "Back to Main Menu"}}}};
}

/**
 * @brief Destructor for BuildingsMenu.
 * Cleans up any resources used by the menu.
 */
BuildingsMenu::~BuildingsMenu() {}

/**
 * @brief Displays the BuildingsMenu to the user.
 * Renders the options and sections using the inherited displayMenu() method.
 */
void BuildingsMenu::display() const
{
    displayMenu(); // Use the inherited displayMenu() function to show the menu
}

/**
 * @brief Handles user input for the Buildings menu.
 * Responds to user choices by navigating to the appropriate submenu or viewing stats.
 */
void BuildingsMenu::handleInput()
{
    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt(); // Display prompt for user input
        std::cin >> choice;

        switch (choice)
        {
        case '1': // Buy Transport
            MenuManager::instance().setCurrentMenu(Menu::BUY_TRANSPORT);
            choosing = false;
            break;
        case '2': // Buy Economic Building
            MenuManager::instance().setCurrentMenu(Menu::BUY_ECONOMIC_BUILDING);
            choosing = false;
            break;
        case '3': // Buy Residential Building
            MenuManager::instance().setCurrentMenu(Menu::BUY_RESIDENTIAL_BUILDING);
            choosing = false;
            break;
        case '4': // Buy Service Building
            MenuManager::instance().setCurrentMenu(Menu::BUY_SERVICE);
            choosing = false;
            break;
        case '5': // Buy Amenity
            MenuManager::instance().setCurrentMenu(Menu::BUY_AMENITY);
            choosing = false;
            break;
        case '6': // Buy Utility
            MenuManager::instance().setCurrentMenu(Menu::BUY_UTILITY);
            choosing = false;
            break;
        case '7': // Buy Resource
            MenuManager::instance().setCurrentMenu(Menu::BUY_RESOURCE);
            choosing = false;
            break;
        case '8': // Sell Building(s)
            MenuManager::instance().setCurrentMenu(Menu::DEMOLISH);
            choosing = false;
            break;
        case 'a': // View Transport Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::BUSSTOP, EntityType::AIRPORT, EntityType::TRAINSTATION}));
            choosing = false;
            break;
        case 'b': // View Economic Building Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::OFFICE, EntityType::SHOPPINGMALL, EntityType::FACTORY}));
            choosing = false;
            break;
        case 'c': // View Residential Building Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::HOUSE, EntityType::APARTMENT}));
            choosing = false;
            break;
        case 'd': // View Service Building Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::HOSPITAL, EntityType::POLICESTATION, EntityType::SCHOOL}));
            choosing = false;
            break;
        case 'e': // View Amenity Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::PARK, EntityType::THEATER, EntityType::MONUMENT}));
            choosing = false;
            break;
        case 'f': // View Utility Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::POWERPLANT, EntityType::WATERSUPPLY, EntityType::WASTEMANAGEMENT, EntityType::SEWAGESYSTEM}));
            choosing = false;
            break;
        case 'g': // View Resource Stats
            MenuManager::instance().setCurrentMenu(std::make_shared<BuildingsStatMenu>(
                std::vector<EntityType>{EntityType::WOODPRODUCER, EntityType::STONEPRODUCER, EntityType::CONCRETEPRODUCER}));
            choosing = false;
            break;
        case 'q': // Navigate back to the Main Menu
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice(); // Handle invalid input
            break;
        }
    }
}
