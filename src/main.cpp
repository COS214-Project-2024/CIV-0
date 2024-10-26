<<<<<<< HEAD
#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
=======
#include <iostream>
#include "city/CivZero.h"

int main()
{
    CivZero::instance().startGame();
    return 0;
}
>>>>>>> dev
