#ifndef CIVZERO_H
#define CIVZERO_H

#include "city/City.h"
#include <optional> // For std::optional

class CivZero
{
public:
    // Get the single instance of CivZero
    static CivZero &instance();

    // Prevent copying and assignment
    CivZero(const CivZero &) = delete;
    CivZero &operator=(const CivZero &) = delete;

    // Method to start the game with options for random city generation and a seed
    void startGame(bool generateRandomCity = false, std::optional<unsigned int> seed = std::nullopt);
    void quit();

private:
    static int const GRID_SIZE = 30;
    // Private constructor and destructor
    CivZero(); // Constructor is private for singleton pattern
    ~CivZero();

    // Internal method for the game loop
    void gameLoop();

    // Internal game state flag (to stop game loop)
    bool running;
};

#endif // CIVZERO_H
