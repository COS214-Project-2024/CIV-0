#ifndef SCHOOL_H
#define SCHOOL_H

#include "ServiceBuilding.h"

/**
 * @brief Class representing a school in the city.
 * 
 * The School class provides education services to the population.
 * It inherits from the ServiceBuilding class.
 */
class School : public ServiceBuilding
{
public:
    /**
     * @brief Default constructor for the School class.
     * 
     * Initializes an empty school object.
     */
    School();

    /**
     * @brief Parameterized constructor for the School class.
     * 
     * @param ec Entity configuration for initializing the school.
     * @param size The size of the school.
     * @param xPos The x-coordinate of the school's location.
     * @param yPos The y-coordinate of the school's location.
     */
    School(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the School class.
     * 
     * @param school A pointer to an existing School object to copy from.
     */
    School(School* school);

    /**
     * @brief Destructor for the School class.
     * 
     * Cleans up resources used by the School object.
     */
    ~School();

    /**
     * @brief Updates the state of the school entity.
     * 
     * Handles changes in the school's state.
     */
    void update();

    /**
     * @brief Clones the school entity.
     * 
     * @return A pointer to a deep copy of the School object.
     */
    Entity* clone();
};

#endif // SCHOOL_H
