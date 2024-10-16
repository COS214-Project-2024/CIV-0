#include "CivZero.h"
#include "menus/MenuManager.h"
#include <iostream>

// Access to the single instance
CivZero &CivZero::getInstance()
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

    MenuManager::getInstance().setCity(city);

    gameLoop(); // Call the internal game loop method
}

void CivZero::setRunningStatus(bool status)
{
    this->running = status;
}

// The game loop itself
void CivZero::gameLoop()
{
    while (running)
    {
        // Display the current menu and handle its input
        MenuManager::getInstance().displayCurrentMenu();
        MenuManager::getInstance().handleCurrentMenuInput();
    }
    std::cout << "Game has ended." << std::endl;
}
