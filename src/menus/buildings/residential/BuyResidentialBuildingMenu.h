#ifndef BUYRESIDENTIALBUILDINGMENU_H
#define BUYRESIDENTIALBUILDINGMENU_H

#include "menus/base/BuyMenu.h"

/**
 * @brief Menu for purchasing residential buildings.
 * This menu allows the user to choose between different types of residential buildings to purchase.
 */
class BuyResidentialBuildingMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyResidentialBuildingMenu.
     * Initializes the residential building purchase menu.
     */
    BuyResidentialBuildingMenu();

    /**
     * @brief Destructor for BuyResidentialBuildingMenu.
     */
    ~BuyResidentialBuildingMenu();

protected:
    /**
     * @brief Provides the selection of residential building types for the user.
     * Overrides the pure virtual method to present specific residential building options.
     * @return The selected EntityType corresponding to the chosen residential building.
     */
    EntityType chooseEntityType() override;
};

#endif // BUYRESIDENTIALBUILDINGMENU_H
