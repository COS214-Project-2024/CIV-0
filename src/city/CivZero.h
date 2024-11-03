/**
 * @file CivZero.h
 * @brief The main game engine file for CivZero.
 */

#ifndef CIVZERO_H
#define CIVZERO_H

#include "city/City.h"
#include <optional> // For std::optional

/**
 * @class CivZero
 * @brief The main game engine class for CivZero.
 *
 * This class implements the singleton pattern to manage game state and control the game loop.
 */
class CivZero
{
public:
    /**
     * @brief Get the single instance of CivZero.
     * @return CivZero& Reference to the singleton instance of CivZero.
     */
    static CivZero &instance();

    // Prevent copying and assignment
    CivZero(const CivZero &) = delete;
    CivZero &operator=(const CivZero &) = delete;

    /**
     * @brief Start the game with options for random city generation and a seed.
     * 
     * @param generateRandomCity If true, generate a random city.
     * @param seed Optional seed for random generation.
     */
    void startGame(bool generateRandomCity = false, std::optional<unsigned int> seed = std::nullopt);

    /**
     * @brief Quit the game.
     */
    void quit();

    /**
     * @brief Increment the game loop counter.
     */
    void incrementGameLoop();

    /**
     * @brief Get the current game loop number.
     * 
     * @return int The current game loop number.
     */
    int getGameLoop();

private:
    static int const GRID_SIZE = 50; ///< The size of the game grid.
    int currentGameLoop = 0; ///< Counter for the current game loop.

    /**
     * @brief Private constructor for the singleton pattern.
     */
    CivZero(); 

    /**
     * @brief Private destructor.
     */
    ~CivZero();

    /**
     * @brief Internal method for the game loop logic.
     */
    void gameLoop();

    bool running; ///< Flag to control the game loop execution.
};

#endif // CIVZERO_H