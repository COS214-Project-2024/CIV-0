#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "ServiceBuilding.h"

/**
 * @brief Class representing a police station in the city.
 * 
 * The PoliceStation class provides law enforcement services.
 * It inherits from the ServiceBuilding class.
 */
class PoliceStation : public ServiceBuilding
{
public:
    /**
     * @brief Parameterized constructor for the PoliceStation class.
     * 
     * @param ec Entity configuration for initializing the police station.
     * @param size The size of the police station.
     * @param xPos The x-coordinate of the police station's location.
     * @param yPos The y-coordinate of the police station's location.
     */
    PoliceStation(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the PoliceStation class.
     * 
     * @param police A pointer to an existing PoliceStation object to copy from.
     */
    PoliceStation(PoliceStation* police);

    /**
     * @brief Destructor for the PoliceStation class.
     * 
     * Cleans up resources used by the PoliceStation object.
     */
    ~PoliceStation();

    /**
     * @brief Updates the state of the police station entity.
     * 
     * Handles changes in the police station's state.
     */
    void update();

    /**
     * @brief Clones the police station entity.
     * 
     * @return A pointer to a deep copy of the PoliceStation object.
     */
    Entity* clone();
};

#endif // POLICESTATION_H
