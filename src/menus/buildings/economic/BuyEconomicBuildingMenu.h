#ifndef BUYECONOMICBUILDINGMENU_H
#define BUYECONOMICBUILDINGMENU_H

#include "menus/base/BuyMenu.h"

/**
 * @brief Represents the menu for buying economic buildings.
 * This menu allows the user to choose different types of economic buildings to purchase.
 */
class BuyEconomicBuildingMenu : public BuyMenu
{
public:
    /**
     * @brief Constructor for BuyEconomicBuildingMenu.
     * Initializes the menu for economic building purchases.
     */
    BuyEconomicBuildingMenu();

    /**
     * @brief Destructor for BuyEconomicBuildingMenu.
     */
    ~BuyEconomicBuildingMenu();

protected:
    /**
     * @brief Displays a list of economic building types for the user to choose from.
     * Overrides the pure virtual method from BuyMenu to provide specific entity types for economic buildings.
     * @return The selected EntityType corresponding to the chosen economic building.
     */
    EntityType chooseEntityType() override;

    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;
};

#endif // BUYECONOMICBUILDINGMENU_H
