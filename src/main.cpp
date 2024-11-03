#include "city/CivZero.h"

/**
 * @brief This is the main. It does main things.
 * @return 0 if everything goes to plan.
 */
int main()
{
    CivZero::instance().startGame(true);
    return 0;
}
