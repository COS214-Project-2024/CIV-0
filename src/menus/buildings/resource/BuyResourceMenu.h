#ifndef BUYRESOURCEMENU_H
#define BUYRESOURCEMENU_H

#include "menus/base/BuyMenu.h"

/**
 * @brief Menu for purchasing resource-producing buildings.
 * This menu allows the user to choose between different types of resource-producing buildings.
 */
class BuyResourceMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyResourceMenu.
     * Initializes the resource-building purchase menu.
     */
    BuyResourceMenu();

    /**
     * @brief Destructor for BuyResourceMenu.
     */
    ~BuyResourceMenu();

protected:
    /**
     * @brief Provides the selection of resource-producing building types for the user.
     * Overrides the pure virtual method to present specific resource-producing building options.
     * @return The selected EntityType corresponding to the chosen resource building.
     */
    EntityType chooseEntityType() override;

    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;
};

#endif // BUYRESOURCEMENU_H
