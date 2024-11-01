#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "entities/base/Entity.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @class Transport
 * @brief Abstract base class representing a transport entity within the game.
 *
 * The Transport class serves as a base for different transport entities,
 * managing shared properties and behaviors such as position, size,
 * and the need for updates in derived classes.
 */
class Transport : public Entity
{
public:
    /**
     * @brief Default constructor for the Transport class.
     */
    Transport();

    /**
     * @brief Constructs a Transport entity with specified attributes.
     * 
     * @param ec Configuration settings for the entity.
     * @param size Size of the transport entity.
     * @param xPos X-coordinate position of the transport.
     * @param yPos Y-coordinate position of the transport.
     */
    Transport(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Transport class.
     * 
     * Creates a new Transport entity by copying the attributes of an existing Transport.
     * 
     * @param transport Pointer to the Transport object to be copied.
     */
    Transport(Transport* transport);

    /**
     * @brief Virtual destructor for the Transport class.
     */
    virtual ~Transport();

    /**
     * @brief Updates the state of the transport entity.
     * 
     * This method must be implemented in derived classes to define specific behaviors.
     */
    virtual void update() = 0;

    /**
     * @brief Creates a clone of the transport entity.
     * 
     * This method must be implemented in derived classes to return a copy of the entity.
     * 
     * @return A pointer to the cloned Transport entity.
     */
    virtual Entity* clone() = 0;
};

#endif // TRANSPORT_H