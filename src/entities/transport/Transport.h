#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @class Transport
 * @brief Abstract base class representing a transport entity in the city builder/manager game.
 * 
 * Transport inherits from both Entity and Subject, allowing it to act as an observable
 * entity within the game. It defines the core functionality for transport-related objects
 * that will be implemented by derived classes.
 */
class Transport : public Entity, public Subject
{
public:
    /**
     * @brief Default constructor for the Transport class.
     * 
     * Initializes a new instance of the Transport class with default values.
     */
    Transport();

    /**
     * @brief Parameterized constructor for the Transport class.
     * 
     * @param ec The configuration object containing general entity properties.
     * @param size The size of the transport entity.
     * @param xPos The x-coordinate position of the transport entity on the map.
     * @param yPos The y-coordinate position of the transport entity on the map.
     * 
     * Initializes a new instance of the Transport class with specific values.
     */
    Transport(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Transport class.
     * 
     * @param transport A pointer to an existing Transport object to copy from.
     * 
     * Creates a new Transport instance as a copy of the provided object.
     */
    Transport(Transport* transport);

    /**
     * @brief Virtual destructor for the Transport class.
     * 
     * Ensures proper cleanup of derived classes that extend the Transport class.
     */
    virtual ~Transport();

    /**
     * @brief Pure virtual function to update the state of the transport entity.
     * 
     * This function must be implemented by derived classes to define specific
     * behavior for updating the transport entity.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to clone the transport entity.
     * 
     * This function must be implemented by derived classes to return a deep copy
     * of the transport entity.
     * 
     * @return A pointer to the newly cloned transport entity.
     */
    virtual Entity* clone() = 0;
};

#endif // TRANSPORT_H