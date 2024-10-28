
#ifndef AMENITYFACTORY_H
#define AMENITYFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/amenity/Park.h"
#include "entities/building/amenity/Theater.h"
#include "entities/building/amenity/Monument.h"

/**
 * @class AmenityFactory
 * @brief A factory class for creating various types of amenities.
 * 
 * The AmenityFactory class inherits from the EntityFactory class and provides
 * methods to create small, medium, and large entities of different types.
 * It also includes private helper methods to create specific types of amenities
 * such as parks, theaters, and monuments.
 */
class AmenityFactory : public EntityFactory {
public:
    /**
     * @brief Constructor for the AmenityFactory class.
     */
    AmenityFactory();

    /**
     * @brief Destructor for the AmenityFactory class.
     */
    ~AmenityFactory();

    /**
     * @brief Creates a small entity of the specified type at the given position.
     * 
     * @param type The type of entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a medium entity of the specified type at the given position.
     * 
     * @param type The type of entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a large entity of the specified type at the given position.
     * 
     * @param type The type of entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);

private:
    /**
     * @brief Creates a park of the specified size at the given position.
     * 
     * @param size The size of the park to create.
     * @param xPos The x-coordinate of the park's position.
     * @param yPos The y-coordinate of the park's position.
     * @return A pointer to the created Entity.
     */
    Entity* createPark(Size size, int xPos, int yPos);

    /**
     * @brief Creates a theater of the specified size at the given position.
     * 
     * @param size The size of the theater to create.
     * @param xPos The x-coordinate of the theater's position.
     * @param yPos The y-coordinate of the theater's position.
     * @return A pointer to the created Entity.
     */
    Entity* createTheater(Size size, int xPos, int yPos);

    /**
     * @brief Creates a monument of the specified size at the given position.
     * 
     * @param size The size of the monument to create.
     * @param xPos The x-coordinate of the monument's position.
     * @param yPos The y-coordinate of the monument's position.
     * @return A pointer to the created Entity.
     */
    Entity* createMonument(Size size, int xPos, int yPos);
};

#endif // AMENITYFACTORY_H
