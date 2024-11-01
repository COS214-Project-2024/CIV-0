#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "utils/EntityType.h"
#include "utils/Size.h"
#include "entities/building/service/ServiceBuilding.h"
#include "factory/building/ServiceBuildingFactory.h"
#include "city/City.h"
/**
 * @class ServiceManager
 * @brief Manages the creation and handling of service buildings within the system.
 *
 * The ServiceManager class is responsible for managing service-related operations,
 * including building and configuring various types of service buildings based on
 * specified parameters such as type, size, and position.
 */
class ServiceManager
{
public:
    /**
     * @brief Constructs a new ServiceManager object.
     */
    ServiceManager();

    /**
     * @brief Destroys the ServiceManager object.
     */
    ~ServiceManager();

    /**
     * @brief Builds a new service building.
     *
     * Creates and initializes a service building of the specified type and size at the given
     * position coordinates.
     *
     * @param type The entity type of the service building to create.
     * @param size The size of the service building.
     * @param xPos The x-coordinate position of the service building.
     * @param yPos The y-coordinate position of the service building.
     * @return A pointer to the created ServiceBuilding object.
     */
    void buildService(EntityType type, Size size, int xPos, int yPos);
};

#endif // SERVICEMANAGER_H
