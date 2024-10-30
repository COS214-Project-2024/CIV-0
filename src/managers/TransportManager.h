#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H
#include "utils/EntityType.h"
#include "utils/Size.h"
#include "entities//road/Road.h"
#include "factory/transport/TransportFactory.h"

/**
 * @class TransportManager
 * @brief Manages the construction and maintenance of transportation infrastructure.
 * 
 * The TransportManager class provides functionalities to check if a road can be afforded,
 * build roads, and build public transit systems.
 */
class TransportManager
{
public:
    /**
     * @brief Constructs a new TransportManager object.
     */
    TransportManager();

    /**
     * @brief Destroys the TransportManager object.
     */
    ~TransportManager();

    /**
     * @brief Checks if there are enough resources to build a road.
     * 
     * @return true if a road can be afforded, false otherwise.
     */
    bool canAffordRoad();

    /**
     * @brief Builds a road at the specified coordinates.
     * 
     * @param x The x-coordinate where the road will be built.
     * @param y The y-coordinate where the road will be built.
     * @return true if the road was successfully built, false otherwise.
     */
    bool buildRoad(int x, int y);

    /**
     * @brief Builds a public transit system at the specified coordinates.
     * 
     * @param type The type of public transit system to build.
     * @param size The size of the public transit system.
     * @param x The x-coordinate where the public transit system will be built.
     * @param y The y-coordinate where the public transit system will be built.
     * @return true if the public transit system was successfully built, false otherwise.
     */
    bool buildPublicTransit(EntityType type, Size size, int x, int y);
};

#endif // TRANSPORTMANAGER_H
