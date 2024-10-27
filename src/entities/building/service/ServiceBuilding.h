#ifndef SERVICEBUILDING_H
#define SERVICEBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @brief Abstract class representing a service building in the city.
 * 
 * Service buildings provide essential services such as healthcare, law enforcement, and education.
 * It inherits from the Building and Subject classes.
 */
class ServiceBuilding : public Building
{
public:
    /**
     * @brief Default constructor for the ServiceBuilding class.
     * 
     * Initializes an empty service building object.
     */
    ServiceBuilding();

    /**
     * @brief Parameterized constructor for the ServiceBuilding class.
     * 
     * @param ec Entity configuration for initializing the building.
     * @param size The size of the building.
     * @param xPos The x-coordinate of the building's location.
     * @param yPos The y-coordinate of the building's location.
     */
    ServiceBuilding(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the ServiceBuilding class.
     * 
     * @param service A pointer to an existing ServiceBuilding object to copy from.
     */
    ServiceBuilding(ServiceBuilding* service);

    /**
     * @brief Destructor for the ServiceBuilding class.
     * 
     * Cleans up resources used by the ServiceBuilding object.
     */
    virtual ~ServiceBuilding();

    /**
     * @brief Pure virtual function for updating the state of the service building.
     * 
     * Must be implemented by derived classes to handle building-specific updates.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function for cloning the service building.
     * 
     * @return A pointer to a deep copy of the service building.
     */
    virtual Entity* clone() = 0;
};

#endif // SERVICEBUILDING_H
