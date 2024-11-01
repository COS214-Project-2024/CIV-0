#ifndef AMENITYFACTORY_H
#define AMENITYFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/amenity/Park.h"
#include "entities/building/amenity/Theater.h"
#include "entities/building/amenity/Monument.h"

/**
 * @class AmenityFactory
 * @brief Factory class for creating various amenities, including parks, theaters, and monuments.
 * 
 * Inherits from EntityFactory and provides methods to create different-sized amenities 
 * (small, medium, and large) based on the specified type at given coordinates.
 */
class AmenityFactory : public EntityFactory {
public:
    /**
     * @brief Default constructor for AmenityFactory.
     */
    AmenityFactory();

    /**
     * @brief Destructor for AmenityFactory.
     */
    ~AmenityFactory();

    /**
     * @brief Creates an amenity of the specified type and size at the given position.
     * 
     * @param type The type of amenity to create (e.g., Park, Theater, Monument).
     * @param size The size of the amenity (small, medium, or large).
     * @param xPos The x-coordinate for the amenity's position.
     * @param yPos The y-coordinate for the amenity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

private:
    /**
     * @brief Creates a park of the specified size at the given position.
     * 
     * @param size The size of the park (small, medium, or large).
     * @param xPos The x-coordinate for the park's position.
     * @param yPos The y-coordinate for the park's position.
     * @return A pointer to the created Park entity.
     */
    Entity* createPark(Size size, int xPos, int yPos);

    /**
     * @brief Creates a theater of the specified size at the given position.
     * 
     * @param size The size of the theater (small, medium, or large).
     * @param xPos The x-coordinate for the theater's position.
     * @param yPos The y-coordinate for the theater's position.
     * @return A pointer to the created Theater entity.
     */
    Entity* createTheater(Size size, int xPos, int yPos);

    /**
     * @brief Creates a monument of the specified size at the given position.
     * 
     * @param size The size of the monument (small, medium, or large).
     * @param xPos The x-coordinate for the monument's position.
     * @param yPos The y-coordinate for the monument's position.
     * @return A pointer to the created Monument entity.
     */
    Entity* createMonument(Size size, int xPos, int yPos);
};

#endif // AMENITYFACTORY_H
