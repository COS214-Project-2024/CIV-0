#ifndef BUYUTILITYMENU_H
#define BUYUTILITYMENU_H

#include "menus/base/BuyMenu.h"

/**
 * @brief Menu for purchasing utility buildings.
 * This menu allows the user to choose between different types of utility buildings.
 */
class BuyUtilityMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyUtilityMenu.
     * Initializes the utility-building purchase menu.
     */
    BuyUtilityMenu();

    /**
     * @brief Destructor for BuyUtilityMenu.
     */
    ~BuyUtilityMenu();

protected:
    /**
     * @brief Provides the selection of utility building types for the user.
     * Overrides the pure virtual method to present specific utility building options.
     * @return The selected EntityType corresponding to the chosen utility building.
     */
    EntityType chooseEntityType() override;

    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;
};

#endif // BUYUTILITYMENU_H
