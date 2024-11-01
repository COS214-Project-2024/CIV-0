#include "CivZero.h"
#include "menus/base/MenuManager.h"
#include <iostream>
#include <cstdlib>  // For system()
#include <optional> // For std::optional

// Access to the single instance
CivZero &CivZero::instance()
{
    static CivZero instance; // Singleton instance
    return instance;
}

// Private constructor
CivZero::CivZero() : running(false) { currentGameLoop = 0; }

// Private destructor
CivZero::~CivZero() {}

// Start the game, which initializes the game loop
void CivZero::startGame(bool generateRandomCity, std::optional<unsigned int> seed)
{
    running = true;

    City::instance()->reset(GRID_SIZE, GRID_SIZE);

    CityManager manager;
    if (generateRandomCity)
    {
        manager.generateCity(seed);
        manager.updateCity();
    }
    else
    {
        manager.initializeCity();
    }

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

        if (City::instance()->getMoney() < 0)
        {
            std::cout << "\033[1;30m" << "\n>> "
                      << "\033[1;31m" << "Game Over :("
                      << "\033[0m" << std::endl;
            running = false;
        }
    }
}

void CivZero::incrementGameLoop()
{
    currentGameLoop++;
}

int CivZero::getGameLoop()
{
    return currentGameLoop;
}
