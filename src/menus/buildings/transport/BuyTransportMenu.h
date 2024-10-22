#ifndef BUYTRANSPORTMENU_H
#define BUYTRANSPORTMENU_H

#include "menus/base/BuyMenu.h"

/**
 * @brief Menu for purchasing transport buildings.
 * This menu allows the user to choose between different types of transport buildings.
 */
class BuyTransportMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyTransportMenu.
     * Initializes the transport-building purchase menu.
     */
    BuyTransportMenu();

    /**
     * @brief Destructor for BuyTransportMenu.
     */
    ~BuyTransportMenu();

protected:
    /**
     * @brief Provides the selection of transport building types for the user.
     * Overrides the pure virtual method to present specific transport building options.
     * @return The selected EntityType corresponding to the chosen transport building.
     */
    EntityType chooseEntityType() override;
};

#endif // BUYTRANSPORTMENU_H
