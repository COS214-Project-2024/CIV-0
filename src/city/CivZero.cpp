#include "CivZero.h"
#include "menus/base/MenuManager.h"
#include <iostream>
#include <cstdlib> // For system()

// Access to the single instance
CivZero &CivZero::instance()
{
    static CivZero instance; // Singleton instance
    return instance;
}

// Private constructor
CivZero::CivZero() : running(false)
{
    this->city = new City();
}

// Private destructor
CivZero::~CivZero()
{
    if (city)
        delete city;
}

// Start the game, which initializes the game loop
void CivZero::startGame()
{
    running = true;
    std::cout << "Starting the game..." << std::endl;

    MenuManager::instance().setCity(city);

    gameLoop(); // Call the internal game loop method
}

void CivZero::quit()
{
    this->running = false;
}

// The game loop itself
void CivZero::gameLoop()
{
    while (running)
    {
        MenuManager::instance().clearScreen();
        // Display the current menu and handle its input
        MenuManager::instance().displayCurrentMenu();
        MenuManager::instance().handleCurrentMenuInput();
    }
    std::cout << "Game has ended." << std::endl;
}
