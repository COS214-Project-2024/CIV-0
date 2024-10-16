#include "MainMenu.h"
#include "MenuManager.h"
#include "city/CivZero.h"
#include <iostream>

MainMenu::MainMenu() : IMenu("In-Game Main Menu") // Set the heading here
{
    // Initialize menu options with keys and text
    options = {
        {1, "Build Menu"},
        {2, "View Stats"},
        {3, "Save Game"},
        {4, "Exit to Main Menu"},
        {0, "Quit Game"}};
}

MainMenu::~MainMenu() {}

void MainMenu::display() const
{
    displayMenu();
}

void MainMenu::handleInput()
{
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1: // Open Building Menu
        MenuManager::getInstance().setCurrentMenu("building");
        break;
    case 2: // View Stats (placeholder for stats display)
        std::cout << "Displaying game statistics..." << std::endl;
        break;
    case 3: // Save Game (placeholder for saving the game)
        std::cout << "Game saved successfully!" << std::endl;
        break;
    case 4: // Exit to Main Menu (go back to the start screen)
        std::cout << "Exiting to Main Menu..." << std::endl;
        MenuManager::getInstance().setCurrentMenu("main");
        break;
    case 0: // Quit Game
        CivZero::getInstance().setRunningStatus(false);
        break;
    default:
        std::cout << "Invalid option, please try again." << std::endl;
        break;
    }
}
