#ifndef SHOPPINGMALL_H
#define SHOPPINGMALL_H

#include "EconomicBuilding.h"

/**
 * @class ShoppingMall
 * @brief Concrete class representing a shopping mall in the city builder/manager game.
 * 
 * ShoppingMall is a type of EconomicBuilding that provides retail spaces and attracts customers for shopping activities.
 */
class ShoppingMall : public EconomicBuilding
{
public:
    /**
     * @brief Default constructor for the ShoppingMall class.
     * 
     * Initializes a new instance of the ShoppingMall class with default values.
     */
    ShoppingMall();

    /**
     * @brief Parameterized constructor for the ShoppingMall class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the shopping mall entity.
     * @param xPos The x-coordinate position of the shopping mall on the map.
     * @param yPos The y-coordinate position of the shopping mall on the map.
     * 
     * Initializes a new instance of the ShoppingMall class with specific values.
     */
    ShoppingMall(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the ShoppingMall class.
     * 
     * @param mall A pointer to an existing ShoppingMall object to copy from.
     * 
     * Creates a new ShoppingMall instance as a copy of the provided object.
     */
    ShoppingMall(ShoppingMall* mall);

    /**
     * @brief Destructor for the ShoppingMall class.
     * 
     * Ensures proper cleanup of resources when a ShoppingMall object is destroyed.
     */
    ~ShoppingMall();

    /**
     * @brief Updates the state of the shopping mall entity.
     * 
     * This function handles changes in the mall's state.
     */
    void update();

    /**
     * @brief Clones the shopping mall entity.
     * 
     * Returns a deep copy of the current ShoppingMall object.
     * 
     * @return A pointer to the newly cloned ShoppingMall entity.
     */
    Entity* clone();
};

#endif // SHOPPINGMALL_H