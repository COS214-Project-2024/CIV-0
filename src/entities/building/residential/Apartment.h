#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

/**
 * @class Apartment
 * @brief Represents an apartment building within the game.
 *
 * The Apartment class is a type of ResidentialBuilding, with attributes and behaviors
 * specific to apartment-style residences. This class includes constructors, a destructor,
 * and an implementation of the clone function.
 */
class Apartment : public ResidentialBuilding
{
public:
    /**
     * @brief Default constructor for the Apartment class.
     */
    Apartment();

    /**
     * @brief Constructs an Apartment with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and other properties.
     * @param size Size of the apartment.
     * @param xPos X-coordinate position of the apartment.
     * @param yPos Y-coordinate position of the apartment.
     */
    Apartment(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Apartment class.
     * 
     * Creates a new Apartment by copying the attributes of an existing Apartment.
     * 
     * @param entity Pointer to the Apartment object to be copied.
     */
    Apartment(Apartment* entity);

    /**
     * @brief Destructor for the Apartment class.
     */
    virtual ~Apartment();

    /**
     * @brief Creates a clone of the apartment.
     * 
     * @return A pointer to the cloned Apartment.
     */
    Entity* clone();
};

#endif // APARTMENT_H
