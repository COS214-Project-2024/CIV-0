/**
 * @file BuyAmenityMenu.h
 * @brief Declares the BuyAmenityMenu class for purchasing amenities within the game.
 */

#ifndef BUYAMENITYMENU_H
#define BUYAMENITYMENU_H

#include "menus/base/BuyMenu.h"
#include "managers/AmenityManager.h"

/**
 * @class BuyAmenityMenu
 * @brief Provides a menu interface for purchasing various types of amenities.
 *
 * The BuyAmenityMenu class allows users to select and purchase different amenities,
 * such as parks, theaters, and monuments. It inherits from the BuyMenu base class and
 * implements methods for choosing the type of amenity and building it at specified locations.
 */
class BuyAmenityMenu : public BuyMenu
{
protected:
    /**
     * @brief Displays a list of amenity types for the user to choose from.
     *
     * Overrides the pure virtual method from BuyMenu to provide specific options
     * for selecting amenities. The user can choose among parks, theaters, and monuments.
     * @return The selected EntityType corresponding to the chosen amenity.
     */
    EntityType chooseEntityType() override;

    /**
     * @brief Initiates the construction of the selected amenity.
     *
     * Overrides the buildEntity method to handle the construction process for the chosen amenity,
     * utilizing the AmenityManager to build the selected type at the specified coordinates and size.
     * @param type The type of amenity to be built.
     * @param size The size of the amenity.
     * @param xPos The x-coordinate for the amenity's position.
     * @param yPos The y-coordinate for the amenity's position.
     */
    void buildEntity(EntityType type, Size size, int xPos, int yPos) override;

private:
    AmenityManager amenityManager; ///< Manages the creation and placement of amenities.
};

#endif // BUYAMENITYMENU_H