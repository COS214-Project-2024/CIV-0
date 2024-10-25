#ifndef BUYSERVICEMENU_H
#define BUYSERVICEMENU_H

#include "menus/base/BuyMenu.h"

/**
 * @brief Menu for purchasing service buildings (Police Station, School, Hospital).
 */
class BuyServiceMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyServiceMenu.
     */
    BuyServiceMenu();

    /**
     * @brief Destructor for BuyServiceMenu.
     */
    ~BuyServiceMenu();

protected:
    /**
     * @brief Override to choose service building types.
     * @return The selected EntityType (Police Station, School, or Hospital).
     */
    EntityType chooseEntityType() override;
};

#endif // BUYSERVICEMENU_H
