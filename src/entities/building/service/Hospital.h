#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "ServiceBuilding.h"

/**
 * @brief Class representing a hospital in the city.
 * 
 * The Hospital class provides healthcare services to the population.
 * It inherits from the ServiceBuilding class.
 */
class Hospital : public ServiceBuilding
{
public:
    /**
     * @brief Default constructor for the Hospital class.
     * 
     * Initializes an empty hospital object.
     */
    Hospital();

    /**
     * @brief Parameterized constructor for the Hospital class.
     * 
     * @param ec Entity configuration for initializing the hospital.
     * @param size The size of the hospital.
     * @param xPos The x-coordinate of the hospital's location.
     * @param yPos The y-coordinate of the hospital's location.
     */
    Hospital(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Hospital class.
     * 
     * @param hospital A pointer to an existing Hospital object to copy from.
     */
    Hospital(Hospital* hospital);

    /**
     * @brief Destructor for the Hospital class.
     * 
     * Cleans up resources used by the Hospital object.
     */
    ~Hospital();

    /**
     * @brief Updates the state of the hospital entity.
     * 
     * Handles changes in the hospital's state.
     */
    void update();

    /**
     * @brief Clones the hospital entity.
     * 
     * @return A pointer to a deep copy of the Hospital object.
     */
    Entity* clone();
};

#endif // HOSPITAL_H
