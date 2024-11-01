#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

/**
 * @class House
 * @brief Represents a house building within the game.
 *
 * The House class is a type of ResidentialBuilding, specifically representing standalone
 * housing. It provides constructors, a destructor, and an implementation of the clone function.
 */
class House : public ResidentialBuilding
{
public:
    /**
     * @brief Default constructor for the House class.
     */
    House();

    /**
     * @brief Constructs a House with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and other properties.
     * @param size Size of the house.
     * @param xPos X-coordinate position of the house.
     * @param yPos Y-coordinate position of the house.
     */
    House(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the House class.
     * 
     * Creates a new House by copying the attributes of an existing House.
     * 
     * @param entity Pointer to the House object to be copied.
     */
    House(House* entity);

    /**
     * @brief Destructor for the House class.
     */
    virtual ~House();

    /**
     * @brief Creates a clone of the house.
     * 
     * @return A pointer to the cloned House.
     */
    Entity* clone();
};

#endif // HOUSE_H
