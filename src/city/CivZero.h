#ifndef CIVZERO_H
#define CIVZERO_H

#include "city/City.h"

class CivZero
{
public:
    // Get the single instance of CivZero
    static CivZero &getInstance();

    // Prevent copying and assignment
    CivZero(const CivZero &) = delete;
    CivZero &operator=(const CivZero &) = delete;

    // Method to start the game
    void startGame();
    void setRunningStatus(bool status);

private:
    // Private constructor and destructor
    CivZero(); // Constructor is private for singleton pattern
    ~CivZero();

    // Internal method for the game loop
    void gameLoop();

    // Internal game state flag (to stop game loop)
    bool running;
    City *city;
};

#endif // CIVZERO_H
