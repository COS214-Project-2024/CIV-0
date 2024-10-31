/**
 * @file AmenityManager.h
 * @brief Manages the creation and handling of amenities within the application.
 */

#ifndef AMENITYMANAGER_H
#define AMENITYMANAGER_H

#include "factory/building/AmenityFactory.h"
#include "utils/EntityType.h"
#include "utils/Size.h"

/**
 * @class AmenityManager
 * @brief Responsible for managing amenities by creating and configuring them
 * based on specified types and sizes.
 */
class AmenityManager
{
public:
    /**
     * @brief Constructs a new AmenityManager.
     */
    AmenityManager();

    /**
     * @brief Destroys the AmenityManager and releases any allocated resources.
     */
    ~AmenityManager();

    /**
     * @brief Builds an amenity of a specified type and size at a given position.
     *
     * @param type The type of the amenity to be created.
     * @param size The size specification for the amenity.
     * @param xPos The x-coordinate for the amenity's position.
     * @param yPos The y-coordinate for the amenity's position.
     * @return A pointer to the created Amenity object.
     */
    void buildAmenity(EntityType type, Size size, int xPos, int yPos);
};

#endif // AMENITYMANAGER_H
