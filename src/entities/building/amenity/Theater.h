#ifndef THEATER_H
#define THEATER_H

#include "Amenity.h"

/**
 * @class Theater
 * @brief Represents a theater entity within the game.
 *
 * The Theater class is a specific type of Amenity, providing unique attributes
 * and behaviors related to theaters, such as increasing local entertainment value.
 * This class includes implementations for updating the theater's state and cloning itself.
 */
class Theater : public Amenity
{
public:
    /**
     * @brief Default constructor for the Theater class.
     */
    Theater();

    /**
     * @brief Constructs a Theater with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and properties.
     * @param size Size of the theater.
     * @param xPos X-coordinate position of the theater.
     * @param yPos Y-coordinate position of the theater.
     */
    Theater(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Theater class.
     * 
     * Creates a new Theater by copying the attributes of an existing Theater.
     * 
     * @param theater Pointer to the Theater object to be copied.
     */
    Theater(Theater* theater);

    /**
     * @brief Destructor for the Theater class.
     */
    virtual ~Theater();

    /**
     * @brief Updates the theater's state.
     */
    void update();

    /**
     * @brief Creates a clone of the theater.
     * 
     * @return A pointer to the cloned Theater.
     */
    Entity* clone();
};

#endif // THEATER_H