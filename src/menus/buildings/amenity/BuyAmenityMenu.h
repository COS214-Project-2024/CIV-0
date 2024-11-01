#ifndef BUYAMENITYMENU_H
#define BUYAMENITYMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/AmenityManager.h"

/**
 * @brief Represents the menu for buying amenities.
 * This menu allows the user to choose different types of amenities to purchase.
 */
class BuyAmenityMenu : public BuyMenu
{
protected:
    /**
     * @brief Displays a list of amenity types for the user to choose from.
     * Overrides the pure virtual method from BuyMenu to provide specific entity types for amenities.
     * @return The selected EntityType corresponding to the chosen amenity.
     */
    EntityType chooseEntityType() override;

    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    AmenityManager amenityManager;
};

#endif // BUYAMENITYMENU_H
