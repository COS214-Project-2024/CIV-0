#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "utils/EntityType.h"
#include "utils/Size.h"
#include "entities/building/service/ServiceBuilding.h"
#include "factory/building/ServiceBuildingFactory.h"
#include "city/City.h"
/**
 * @class ServiceManager
 * @brief Manages the creation and destruction of service buildings.
 *
 * The ServiceManager class is responsible for constructing and initializing
 * service buildings of various types and sizes at specified coordinates.
 *
 * @fn ServiceManager::ServiceManager()
 * @brief Constructs a new ServiceManager object.
 *
 * @fn ServiceManager::~ServiceManager()
 * @brief Destroys the ServiceManager object.
 *
 * @fn bool ServiceManager::buildService(EntityType type, Size size, int xPos, int yPos)
 * @brief Builds a new service building.
 *
 * Creates and initializes a service building of the specified type and size at the given
 * position coordinates.
 *
 * @param type The entity type of the service building to create.
 * @param size The size of the service building.
 * @param xPos The x-coordinate position of the service building.
 * @param yPos The y-coordinate position of the service building.
 * @return A boolean indicating success or failure of the building creation.
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
     * @brief Builds a service of the specified type, size, and location within the city.
     * @param type Type of service to build (e.g., School, Hospital).
     * @param size Size of the service (e.g., small, medium, large).
     * @param x X-coordinate in the city grid.
     * @param y Y-coordinate in the city grid.
     */
    bool buildService(EntityType type, Size size, int xPos, int yPos);
};

#endif // SERVICEMANAGER_H