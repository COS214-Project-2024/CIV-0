#ifndef ROAD_H
#define ROAD_H

#include "entities/base/Entity.h"

/**
 * @class Road
 * @brief Represents a road entity within the game.
 *
 * The Road class manages the properties and behavior of road entities, including
 * their position and size. This class provides functionality to update the road's
 * state and to create clones of road entities.
 */
class Road : public Entity
{
public:
    /**
     * @brief Constructs a Road entity with specified attributes.
     *
     * @param ec Configuration settings for the entity.
     * @param size Size of the road entity.
     * @param xPos X-coordinate position of the road.
     * @param yPos Y-coordinate position of the road.
     */
    Road(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Road class.
     *
     * Creates a new Road entity by copying the attributes of an existing Road.
     *
     * @param road Pointer to the Road object to be copied.
     */
    Road(Road *road);

    /**
     * @brief Destructor for the Road class.
     */
    ~Road();

    /**
     * @brief Updates the state of the road entity.
     */
    void update();

    /**
     * @brief Creates a clone of the road entity.
     *
     * @return A pointer to the cloned Road entity.
     */
    Entity *clone();
};

#endif // ROAD_H
